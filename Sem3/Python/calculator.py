import tkinter as tk
import re

expression = "0"
BG_COLOR = "#ede9e9"
just_evaluated = False

def format_display(expr=None):
    if expr is None:
        expr = expression

    formatted = expr
    formatted = formatted.replace("**2", "²")
    formatted = formatted.replace("**3", "³")
    formatted = re.sub(r'(\d+)\*\*0\.5', r'√(\1)', formatted)
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
        if actual in "0123456789.":
            expression = actual
        else:
            expression += actual
        just_evaluated = False

    else:
        if expression == "0":
            if actual in "0123456789.":
                expression = actual
            elif actual in "+-*/":
                expression += actual
            else:
                return
        else:
            expression += actual

    display_var.set(format_display())



def insert_open_bracket():
    global expression

    last = expression[-1]

    if last.isdigit() or last == ')':
        expression += '*('
    else:
        expression += '('

    display_var.set(format_display())


def insert_close_bracket():
    global expression

    open_count = expression.count('(')
    close_count = expression.count(')')

    if close_count < open_count and expression[-1] not in "+-*/(":
        expression += ')'

    display_var.set(format_display())


def clear_display():
    global expression, just_evaluated
    expression = "0"
    display_var.set("0")
    history_var.set("")
    just_evaluated = False


def backspace():
    global expression, just_evaluated

    just_evaluated = False

    if expression == "0":
        return

    expression = expression[:-1]

    if expression == "":
        expression = "0"

    display_var.set(format_display())


def calculate():
    global expression, just_evaluated

    original_expr = expression

    open_count = expression.count('(')
    close_count = expression.count(')')
    expression += ')' * (open_count - close_count)

    try:
        result = str(eval(expression))

        history_var.set(f"{format_display(original_expr)}={result}")
        expression = result
        display_var.set(result)

        just_evaluated = True

    except:
        history_var.set(f"{format_display(original_expr)}=Error")
        expression = "0"
        display_var.set("Error")

        just_evaluated = True


def reciprocal():
    global expression
    expression = f"1/({expression})"
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

    if start > 0 and expression[start-1] == '-':
        expression = expression[:start-1] + number
    else:
        expression = expression[:start] + '-' + number

    display_var.set(format_display())


def key_event(event):
    key = event.char

    if key == "":
        return

    if key in "0123456789+-*/.":
        update_display(key)

    elif key == "(":
        insert_open_bracket()

    elif key == ")":
        insert_close_bracket()

    elif event.keysym == "Return":
        calculate()

    elif event.keysym == "Escape":
        clear_display()

    elif event.keysym == "BackSpace":
        backspace()



root = tk.Tk()
root.title("Calculator")
root.geometry("320x550")
root.resizable(False, False)
root.configure(bg=BG_COLOR)

root.bind_all("<Tab>", lambda e: "break")
root.bind("<Key>", key_event)
root.bind("<Delete>", lambda e: backspace())


history_var = tk.StringVar()

history_display = tk.Label(root,
                           textvariable=history_var,
                           font=("Segoe UI", 12),
                           bg=BG_COLOR,
                           anchor="e",
                           fg="gray")

history_display.pack(fill="both", padx=10, pady=(5, 0))


display_var = tk.StringVar(value="0")

display = tk.Entry(root,
                   textvariable=display_var,
                   font=("Segoe UI", 24),
                   bd=0,
                   bg=BG_COLOR,
                   justify="right",
                   state="readonly")

display.pack(fill="both", ipadx=8, ipady=20, padx=10, pady=(0, 10))


frame = tk.Frame(root, bg=BG_COLOR)
frame.pack(expand=True, fill="both")

for i in range(6):
    frame.rowconfigure(i, weight=1)

for j in range(4):
    frame.columnconfigure(j, weight=1)


def create_button(text, row, col, cmd, bg="#ffffff"):
    btn = tk.Button(frame,
                    text=text,
                    font=("Segoe UI", 14),
                    bg=bg,
                    bd=0,
                    command=cmd,
                    takefocus=0)

    btn.grid(row=row, column=col, padx=5, pady=5, sticky="nsew")



create_button('%', 0, 0, lambda: update_display('%'))
create_button('x³', 0, 1, lambda: update_display("**3"))
create_button('C', 0, 2, clear_display)
create_button('⌫', 0, 3, backspace)

create_button('1/x', 1, 0, reciprocal)
create_button('x²', 1, 1, lambda: update_display("**2"))
create_button('√x', 1, 2, lambda: update_display("**0.5"))
create_button('÷', 1, 3, lambda: update_display('÷'))

create_button('7', 2, 0, lambda: update_display('7'))
create_button('8', 2, 1, lambda: update_display('8'))
create_button('9', 2, 2, lambda: update_display('9'))
create_button('×', 2, 3, lambda: update_display('×'))

create_button('4', 3, 0, lambda: update_display('4'))
create_button('5', 3, 1, lambda: update_display('5'))
create_button('6', 3, 2, lambda: update_display('6'))
create_button('-', 3, 3, lambda: update_display('-'))

create_button('1', 4, 0, lambda: update_display('1'))
create_button('2', 4, 1, lambda: update_display('2'))
create_button('3', 4, 2, lambda: update_display('3'))
create_button('+', 4, 3, lambda: update_display('+'))

create_button('+/-', 5, 0, toggle_sign)
create_button('0', 5, 1, lambda: update_display('0'))
create_button('.', 5, 2, lambda: update_display('.'))
create_button('=', 5, 3, calculate, bg="#6c5ce7")


root.mainloop()