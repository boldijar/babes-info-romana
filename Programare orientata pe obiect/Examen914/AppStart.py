'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Domain.Validator import *
from Controller.Controller import *
from Repository.WordRepo import *
from UI.UI import *

repo = WordRepo("input.txt")
valid = Validator(repo)
control = Controller(repo,valid)
ui = UI(control)
ui.Console()