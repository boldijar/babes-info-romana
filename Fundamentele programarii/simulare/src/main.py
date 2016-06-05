'''
Created on Dec 10, 2014

@author: Iulian
'''
from repository.repository import Repository
from controller.bicicleta_controller import Bicicleta_controller
from ui.console import Console

repo = Repository("produse.txt")
contr = Bicicleta_controller(repo)
consola = Console(contr)

consola.UI()