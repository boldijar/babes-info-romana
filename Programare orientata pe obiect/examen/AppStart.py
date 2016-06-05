'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Repository.LabRepo import *
from Repository.StudentRepo import *
from Controler.LabControler import *
from Controler.Validator import *
from Controler.Validator import *
from UI.Ui import *

studRepo = StudentRepo("student.txt")
labRepo = LabRepo("labs.txt")
validator = Validator(studRepo,labRepo)
controler = Controler(labRepo, studRepo,validator)
ui = UI(controler)
ui.Console()