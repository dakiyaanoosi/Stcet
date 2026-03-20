import tkinter as tk
from home_frame import HomeFrame
from form_frame import FormFrame

PRIMARY = "#0b3d91"
BG = "#f5f7fa"

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("StudentDB")
        self.geometry("1024x768")
        self.resizable(False, False)
        self.configure(bg=BG)

        container = tk.Frame(self)
        container.pack(fill="both", expand=True)

        self.frames = {}

        for F in (HomeFrame, FormFrame):
            frame = F(container, self)
            self.frames[F.__name__] = frame
            frame.place(relwidth=1, relheight=1)

        self.show_frame("HomeFrame")

    def show_frame(self, frame_name):
        frame = self.frames[frame_name]
        frame.tkraise()