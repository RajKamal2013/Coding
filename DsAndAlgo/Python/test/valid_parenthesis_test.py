import unittest

from src.Practice.src.valid_parentheses import ValidParenthesis


class ValidParenthesisTest(unittest.TestCase):
    def test_isValid(self):
        validator = ValidParenthesis()

        s = "[[["
        self.assertFalse(ValidParenthesis.isValid(s))  # add assertion here
        s = "[[[((]])])"
        self.assertTrue(ValidParenthesis.isValid(s))


if __name__ == '__main__':
    unittest.main()
