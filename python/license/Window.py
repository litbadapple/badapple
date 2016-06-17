from tkinter import *
from tkinter.filedialog import *
from tkinter.messagebox import showerror
import license
from time import strptime
from datetime import *

class Window(object):
    def __init__(self, master=None):
        self.root = master
        self.license = license.License()
        self.create_frame()

    def create_frame(self):
        names = ["序列号:", "MAC地址:", "时间:", "有效期:", "AP数量:"]
        self.Lablelist = []
        self.EntryList = []

        for i in range(0, 5):
            self.Lablelist.append(Label(self.root, text=names[i], font=("宋体", 14, "normal")))
            self.EntryList.append(Entry(self.root, font=("宋体", 14, "normal")))

        self.importButton = Button(self.root, text="导入", command=self.openfile)
        self.generateButton = Button(self.root, text="生成授权信息", command=self.generate)
        self.exportButton = Button(self.root, text="导出", command=self.savefile)
        self.licenseText = Text(self.root, font=("宋体", 12, "normal"), height=6, bg="gray")

        for i in range(0, 5):
            self.Lablelist[i].grid(row=i, column=0, padx=15, pady=15, sticky="e")
            self.EntryList[i].grid(row=i, column=1, columnspan=5, padx=15, pady=15, sticky="ew")

        self.licenseText.grid(row=5, column=1, columnspan=5, padx=15, pady=15, sticky="e")
        self.importButton.grid(row=6, column=3, padx=15, pady=15, sticky="ew")
        self.generateButton.grid(row=6, column=4, padx=15, pady=15, sticky="ew")
        self.exportButton.grid(row=6, column=5, padx=15, pady=15, sticky="ew")


    def openfile(self):
        file_path = askopenfilename(filetypes=[("text file", "*.txt"), ("all", "*.*")])

        if not file_path:
            return

        with open(file_path,"r") as myfile:
            data = myfile.read()
            t = self.license.decrypt(data).split('/')

            self.EntryList[0].insert("0", t[0])
            self.EntryList[1].insert("0", t[1])
            self.EntryList[2].insert("0", date.today().isoformat())

            self.licenseText.insert("0.0", data)
            self.licenseText.see("end")


    def generate(self):
        t = []
        for i in range(0, 5):
            t.append(self.EntryList[i].get())

        if len(t[2]) == 0 or len(t[3]) == 0 or len(t[4]) == 0:
            self.generate_by_file()
        else:
            t.append(t[4])
            t.append("0")
            e = strptime(t[2], "%Y-%m-%d")
            y,m,d = e[0:3]
            t[4] = (date(y, m, d)+timedelta(days=int(t[3]))).isoformat()
            self.generate_license(t)

    def savefile(self):
        filename = asksaveasfilename()

        if filename:
            self.generate()
            open(filename, 'w').write(self.key)

    def generate_by_file(self):
        content = self.licenseText.get("0.0", END)
        if not content:
            showerror("请导入授权信息")
            return
        t = self.license.decrypt(content).split('/')
        t.append(date.today().isoformat())
        t.append("365")
        t.append((date.today()+timedelta(days=365)).isoformat())
        t.append("2")
        t.append("0")
        self.generate_license(t)


    def generate_license(self, data):
        t = "/".join(data)
        self.key = self.license.encrypt(t)
        for i in range(0, 5):
            self.EntryList[i].delete(0, END)
            self.EntryList[i].insert(0, data[i+1] if i==4 else data[i])

        self.licenseText.delete("0.0", END)
        self.licenseText.insert("0.0", self.key)

root = Tk() # create a root window
root.title("Raytight Portal License")
root.resizable(False, False)
Window(master=root)
root.mainloop() # create an event loop