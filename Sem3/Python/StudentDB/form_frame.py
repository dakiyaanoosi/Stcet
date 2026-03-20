import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
from excel_handler import save_to_excel
from utils import validate_data, show_success, validate_dob

PRIMARY = "#0b3d91"
BG = "#f5f7fa"

class FormFrame(tk.Frame):
    def __init__(self, parent, controller):
        super().__init__(parent, bg=BG)

        header = tk.Frame(self, bg=PRIMARY, height=100)
        header.pack(fill="x")

        logo = ImageTk.PhotoImage(Image.open("assets/logo.png").resize((80, 80)))
        nba = ImageTk.PhotoImage(Image.open("assets/nba.png").resize((80, 80)))

        self.logo = logo
        self.nba = nba

        tk.Label(header, image=logo, bg=PRIMARY).pack(side="left", padx=10)

        text_frame = tk.Frame(header, bg=PRIMARY)
        text_frame.pack(side="left")

        tk.Label(
            text_frame,
            text="ST. THOMAS' COLLEGE OF ENGINEERING & TECHNOLOGY",
            font=("Arial", 16, "bold"),
            fg="white",
            bg=PRIMARY
        ).pack(anchor="w")

        tk.Label(
            text_frame,
            text="APPROVED BY AICTE, NEW DELHI & AFFILIATED TO MAKAUT, W.B",
            font=("Arial", 10),
            fg="white",
            bg=PRIMARY
        ).pack(anchor="w")

        nba_box = tk.Frame(header, bg="white", padx=5, pady=5)
        nba_box.pack(side="right", padx=10)
        tk.Label(nba_box, image=nba, bg="white").pack()

        container = tk.Frame(self, bg=BG)
        container.pack(expand=True)

        card = tk.Frame(container, bg="white")
        card.pack(pady=30)

        form_area = tk.Frame(card, bg="white")
        form_area.grid(padx=60, pady=40)
        form_area.focus_set()

        form_area.grid_columnconfigure(0, weight=1)
        form_area.grid_columnconfigure(1, weight=3)

        name_var = tk.StringVar()
        address_var = tk.StringVar()
        dob_var = tk.StringVar()
        dept_var = tk.StringVar()
        x_var = tk.StringVar()
        xii_var = tk.StringVar()
        gender_var = tk.StringVar(value="")

        def field(label, row, var):
            tk.Label(
                form_area,
                text=label,
                bg="white",
                fg="#333",
                font=("Segoe UI", 11),
                width=15,
                anchor="w"
            ).grid(row=row, column=0, pady=10, ipadx=12, sticky="w")

            entry = tk.Entry(
                form_area,
                textvariable=var,
                font=("Segoe UI", 12),
                bd=1,
                relief="solid",
                width=30
            )
            entry.grid(row=row, column=1, pady=10, padx=10, ipady=6, sticky="ew")
            return entry

        field("Name", 0, name_var)
        field("Address", 1, address_var)
        field("DOB (DD/MM/YYYY)", 2, dob_var)

        tk.Label(
            form_area,
            text="Department",
            bg="white",
            fg="#333",
            font=("Segoe UI", 11),
            width=15,
            anchor="w"
        ).grid(row=3, column=0, pady=10, ipadx=12, sticky="w")

        dept = ttk.Combobox(
            form_area,
            textvariable=dept_var,
            values=["CSE", "IT", "AIML", "ECE", "EE"],
            state="readonly",
            font=("Segoe UI", 11)
        )
        dept.grid(row=3, column=1, pady=10, padx=10, ipady=6, sticky="ew")

        field("Class X %", 4, x_var)
        field("Class XII %", 5, xii_var)

        tk.Label(
            form_area,
            text="Gender",
            bg="white",
            fg="#333",
            font=("Segoe UI", 11),
            width=15,
            anchor="w"
        ).grid(row=6, column=0, pady=10, ipadx=12, sticky="w")

        gender_frame = tk.Frame(form_area, bg="white")
        gender_frame.grid(row=6, column=1, pady=10, padx=10, ipady=6, sticky="ew")

        tk.Radiobutton(
            gender_frame,
            text="Male",
            variable=gender_var,
            value="Male",
            bg="white",
            tristatevalue=0,
        ).pack(side="left", padx=10)

        tk.Radiobutton(
            gender_frame,
            text="Female",
            variable=gender_var,
            value="Female",
            bg="white",
            tristatevalue=0,
        ).pack(side="left", padx=10)

        def primary_button(parent, text, cmd):
            return tk.Button(
                parent,
                text=text,
                font=("Segoe UI", 11, "bold"),
                bg=PRIMARY,
                fg="white",
                activebackground="#062c6f",
                bd=0,
                padx=25,
                pady=10,
                cursor="hand2",
                command=cmd
            )

        def secondary_button(parent, text, cmd):
            return tk.Button(
                parent,
                text=text,
                font=("Segoe UI", 11),
                bg="white",
                fg="black",
                bd=1,
                relief="solid",
                padx=25,
                pady=10,
                cursor="hand2",
                command=cmd
            )

        def reset_form():
            name_var.set("")
            address_var.set("")
            dob_var.set("")
            dept_var.set("")
            x_var.set("")
            xii_var.set("")
            gender_var.set("")

            form_area.focus_set()

        def submit():
            data = [
                name_var.get(),
                address_var.get(),
                dob_var.get(),
                dept_var.get(),
                x_var.get(),
                xii_var.get(),
                gender_var.get()
            ]

            if not validate_dob(dob_var.get()):
                return

            if validate_data(data):
                save_to_excel(data)
                show_success()
                reset_form()
                form_area.focus_set()

        btn_frame = tk.Frame(self, bg=BG)
        btn_frame.pack(pady=20)

        primary_button(btn_frame, "Submit", submit).grid(row=0, column=0, padx=15)
        secondary_button(btn_frame, "Reset", reset_form).grid(row=0, column=1, padx=15)
        secondary_button(
            btn_frame,
            "Back",
            lambda: [form_area.focus_set(), controller.show_frame("HomeFrame")]
        ).grid(row=0, column=2, padx=15)