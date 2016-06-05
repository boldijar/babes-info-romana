'''
Created on Jan 25, 2013

@author: Vlad Mihai
'''
from Repository.ContactRepo import *
from Controller.ControlAgenda import *
from UI.UI import *

r= ContactRepo("file.txt")
v = Validator(r)
c = Controller(r,v)
u = UI(c)
u.Console()