import tkinter as tk
from PIL import Image, ImageTk
from excel_handler import open_excel_file

PRIMARY = "#0b3d91"
BG = "#f5f7fa"

class HomeFrame(tk.Frame):
    def __init__(self, parent, controller):
        super().__init__(parent, bg=BG)

        header = tk.Frame(self, bg=PRIMARY, height=100)
        header.pack(fill="x")

        logo = ImageTk.PhotoImage(Image.open("assets/logo.png").resize((80,80)))
        nba = ImageTk.PhotoImage(Image.open("assets/nba.png").resize((80,80)))

        self.logo = logo
        self.nba = nba

        tk.Label(header, image=logo, bg=PRIMARY).pack(side="left", padx=10)

        text_frame = tk.Frame(header, bg=PRIMARY)
        text_frame.pack(side="left")

        tk.Label(text_frame,
                 text="ST. THOMAS' COLLEGE OF ENGINEERING & TECHNOLOGY",
                 font=("Arial", 16, "bold"),
                 fg="white", bg=PRIMARY).pack(anchor="w")

        tk.Label(text_frame,
                 text="APPROVED BY AICTE, NEW DELHI & AFFILIATED TO MAKAUT, W.B",
                 font=("Arial", 10),
                 fg="white", bg=PRIMARY).pack(anchor="w")

        nba_box = tk.Frame(header, bg="white", padx=5, pady=5)
        nba_box.pack(side="right", padx=10)
        tk.Label(nba_box, image=nba, bg="white").pack()

        body = tk.Frame(self, bg=BG)
        body.pack(expand=True)

        def btn(text, cmd):
            return tk.Button(
                body,
                text=text,
                font=("Arial", 14, "bold"),
                bg=PRIMARY,
                fg="white",
                activebackground="#062c6f",
                width=20,
                height=2,
                bd=0,
                cursor="hand2",
                command=cmd
            )
        
        def secondary_button(parent, text, cmd):
            return tk.Button(
                parent,
                text=text,
                font=("Arial", 14),
                bg="white",
                fg="black",
                bd=1,
                relief="solid",
                padx=20,
                pady=8,
                cursor="hand2",
                command=cmd
            )

        btn("Add New Student",
            lambda: controller.show_frame("FormFrame")).pack(pady=15)

        btn("View Records", open_excel_file).pack(pady=15)

        secondary_button(body, "Exit", controller.destroy).pack(pady=15)