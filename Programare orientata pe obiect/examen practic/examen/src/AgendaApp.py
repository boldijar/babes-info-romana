from Repository.ContactRepository import Repository
from UI.AgendaController import Controller
from UI.AgendaUI import Consola


def main():
    repo = Repository("agenda.txt")
    contr = Controller(repo)
    cons = Consola(contr)
    cons.run()

main()