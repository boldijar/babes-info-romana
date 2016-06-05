'''
Created on Nov 11, 2014

@author: Iulian
'''

import unittest

from test.catalog.domain import test_entities, test_validators, test_dto
from test.catalog.repository import test_repository
from test.catalog.controller import test_student_controller,\
    test_discipline_controller, test_student_discipline_controller

all_suites = unittest.TestSuite( [test_entities.suite(), test_repository.suite(), test_student_controller.suite(),
                                 test_discipline_controller.suite(), test_validators.suite(), 
                                 test_student_discipline_controller.suite(), test_dto.suite() ])

if __name__ == '__main__':
    unittest.TextTestRunner(verbosity=2).run(all_suites)