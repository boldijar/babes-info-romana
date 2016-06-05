'''
Created on 8 dec. 2014

@author: teo
'''
from domain.validator import Validator
from repository.repo import RepoFilme
from controller.contFilm import ControllerFilm
from ui.consola import Console

valid = Validator()
repo = RepoFilme('filme.txt')
contr = ControllerFilm(repo, valid)
consola = Console(contr)

consola.showUI()