'''

@author: radu

Generate all sequences of n parentheses that close correctly.
 Example: n=4 there are two solutions: (()) and ()()
'''
from s14p3.backtr_solver import BacktrackingSolver
from s14p3.problems import parantheses
from s14p3.ui import Console


def tst_parantheses():
    bs = BacktrackingSolver(parantheses.first, \
                            parantheses.consistent, \
                            parantheses.is_solution, \
                            parantheses.get_solution, \
                            parantheses.next_elem, \
                            parantheses.initial_value)

    cons = Console(bs)
    cons.run_menu()


if __name__ == '__main__':
    tst_parantheses()
