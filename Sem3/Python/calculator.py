import tkinter as tk
import re
import math
from decimal import Decimal, getcontext

getcontext().prec = 20

expression = "0"
BG_COLOR = "#ede9e9"
just_evaluated = False


def format_display(expr=None):
    if expr is None:
        expr = expression

    formatted = expr
    formatted = formatted.replace("math.sqrt(", "√(")
    formatted = formatted.replace("**2", "²")
    formatted = formatted.replace("**3", "³")
    formatted = formatted.replace('*', '×').replace('/', '÷')

    return formatted


def update_display(value):
    global expression, just_evaluated

    if value == '×':
        actual = '*'
    elif value == '÷':
        actual = '/'
    else:
        actual = value

    if just_evaluated:
        if actual in "0123456789":
            expression = actual
        else:
            expression += actual
        just_evaluated = False
        display_var.set(format_display())
        return

    if expression == "0":
        if actual in "0123456789":
            expression = actual
        elif actual == '(':
            expression = '('
        else:
            expression += actual
    else:
        last = expression[-1]
        if actual.isdigit() and (last == ')' or expression.endswith("**2") or expression.endswith("**3")):
            expression += '*' + actual
        elif actual == '(' and (last.isdigit() or last == ')'):
            expression += '*('
        else:
            expression += actual

    display_var.set(format_display())


def insert_open_bracket():
    global expression, just_evaluated
    just_evaluated = False

    if not expression or expression == "0":
        expression = "("
    else:
        last = expression[-1]
        if last.isdigit() or last == ')':
            expression += '*('
        else:
            expression += '('

    display_var.set(format_display())


def insert_close_bracket():
    global expression
    if expression.count('(') > expression.count(')') and expression[-1] not in "+-*/(":
        expression += ')'
    display_var.set(format_display())


def clear_display():
    global expression, just_evaluated
    expression = "0"
    display_var.set("0")
    history_var.set("")
    just_evaluated = False


def clear_entry():
    global expression, just_evaluated
    expression = "0"
    display_var.set("0")
    just_evaluated = False


def backspace():
    global expression, just_evaluated

    just_evaluated = False

    if not expression or expression == "0":
        expression = "0"
        display_var.set("0")
        return

    if expression.endswith("**2") or expression.endswith("**3"):
        expression = expression[:-3]
    elif expression.endswith("math.sqrt("):
        expression = expression[:-10]
    else:
        expression = expression[:-1]

    if not expression:
        expression = "0"

    display_var.set(format_display())


def calculate():
    global expression, just_evaluated
    original = expression

    open_b = expression.count('(')
    close_b = expression.count(')')
    if open_b > close_b:
        expression += ')' * (open_b - close_b)

    if "()" in expression or expression[-1] in "+-*/":
        history_var.set("Invalid Format Used")
        expression = original
        return

    try:
        safe_dict = {"math": math, "Decimal": Decimal}
        result_val = eval(expression, {"__builtins__": None}, safe_dict)

        if float(result_val).is_integer():
            result = str(int(result_val))
        else:
            result = format(float(result_val), '.10g')

        history_var.set(f"{format_display(original)}=")
        expression = result
        display_var.set(result)
        just_evaluated = True
    except ZeroDivisionError:
        history_var.set("Cannot divide by zero")
        expression = original
    except Exception:
        history_var.set("Error")
        expression = original


def square():
    global expression, just_evaluated
    if expression == "0":
        return
    just_evaluated = False
    expression = f"({expression})**2"
    display_var.set(format_display())


def cube():
    global expression, just_evaluated
    if expression == "0":
        return
    just_evaluated = False
    expression = f"({expression})**3"
    display_var.set(format_display())


def square_root():
    global expression, just_evaluated
    if just_evaluated:
        expression = display_var.get()
        just_evaluated = False
    if expression == "0":
        return

    temp_expr = expression.replace('√', 'math.sqrt').replace('²', '**2').replace('³', '**3')
    temp_expr = temp_expr.replace('×', '*').replace('÷', '/')

    i = len(temp_expr) - 1
    if temp_expr[i] == ')':
        count, j = 0, i
        while j >= 0:
            if temp_expr[j] == ')':
                count += 1
            elif temp_expr[j] == '(':
                count -= 1
                if count == 0:
                    break
            j -= 1
        if j >= 9 and temp_expr[j-9:j] == "math.sqrt":
            start_index = j - 9
        else:
            start_index = j
        operand = temp_expr[start_index:i+1]
        expression = temp_expr[:start_index] + f"math.sqrt({operand})"

    elif temp_expr[i].isdigit() or temp_expr[i] == '.':
        j = i
        while j >= 0 and (temp_expr[j].isdigit() or temp_expr[j] == '.'):
            j -= 1
        operand = temp_expr[j+1:i+1]
        expression = temp_expr[:j+1] + f"math.sqrt({operand})"

    else:
        return

    display_var.set(format_display())


def reciprocal():
    global expression, just_evaluated
    if expression == "0":
        return
    expression = f"1/({expression})"
    just_evaluated = False
    display_var.set(format_display())


def toggle_sign():
    global expression, just_evaluated
    just_evaluated = False

    if expression == "0":
        return

    match = re.search(r'(\d+\.?\d*)$', expression)
    if not match:
        return

    start, end = match.span()
    number = match.group()

    if start > 0 and expression[start - 1] == '-':
        expression = expression[:start - 1] + number
    else:
        expression = expression[:start] + '-' + number

    display_var.set(format_display())


def key_event(event):
    if event.char == "":
        return

    if event.char in "0123456789+-*/.":
        update_display(event.char)

    elif event.char == "(":
        insert_open_bracket()

    elif event.char == ")":
        insert_close_bracket()

    elif event.keysym == "Return":
        calculate()

    elif event.keysym == "BackSpace":
        backspace()

    elif event.keysym == "Escape":
        clear_display()


root = tk.Tk()
root.title("Calculator")
root.geometry("320x550")
root.resizable(False, False)
root.configure(bg=BG_COLOR)
root.bind("<Key>", key_event)

history_var = tk.StringVar()
tk.Label(root, textvariable=history_var, font=("Segoe UI", 12), bg=BG_COLOR, anchor="e", fg="gray").pack(fill="both", padx=10, pady=(5, 0))

display_var = tk.StringVar(value="0")
tk.Entry(root, textvariable=display_var, font=("Segoe UI", 24), bd=0, bg=BG_COLOR, justify="right", state="readonly").pack(fill="both", ipadx=8, ipady=20, padx=10, pady=(0, 10))

frame = tk.Frame(root, bg=BG_COLOR)
frame.pack(expand=True, fill="both")
for i in range(6): frame.rowconfigure(i, weight=1)
for j in range(4): frame.columnconfigure(j, weight=1)


def btn(text, r, c, cmd, bg="#fff", fg="#000"):
    tk.Button(frame, text=text, font=("Segoe UI", 14), bg=bg, fg=fg, bd=0, command=cmd, takefocus=0).grid(row=r, column=c, padx=5, pady=5, sticky="nsew")


btn('1/x', 0, 0, reciprocal)
btn('CE', 0, 1, clear_entry)
btn('C', 0, 2, clear_display)
btn('⌫', 0, 3, backspace)

btn('x²', 1, 0, square)
btn('x³', 1, 1, cube)
btn('√x', 1, 2, square_root)
btn('+', 1, 3, lambda: update_display('+'))

btn('7', 2, 0, lambda: update_display('7'))
btn('8', 2, 1, lambda: update_display('8'))
btn('9', 2, 2, lambda: update_display('9'))
btn('×', 2, 3, lambda: update_display('×'))

btn('4', 3, 0, lambda: update_display('4'))
btn('5', 3, 1, lambda: update_display('5'))
btn('6', 3, 2, lambda: update_display('6'))
btn('-', 3, 3, lambda: update_display('-'))

btn('1', 4, 0, lambda: update_display('1'))
btn('2', 4, 1, lambda: update_display('2'))
btn('3', 4, 2, lambda: update_display('3'))
btn('+', 4, 3, lambda: update_display('+'))

btn('+/-', 5, 0, toggle_sign)
btn('0', 5, 1, lambda: update_display('0'))
btn('.', 5, 2, lambda: update_display('.'))
btn('=', 5, 3, calculate, bg="#6c5ce7", fg="#fff")

root.mainloop()