
class ValidParenthesis(object):
    @staticmethod
    def isValid(s: str) -> bool:
        """
        type s: str
        rtype: bool
        """
        bracket =  middle_bracket = close_bracket = 0
        for ch in s:
            match ch:
                case '(':
                    bracket = bracket + 1
                case ')':
                    bracket = bracket  - 1
                case '{':
                    middle_bracket = middle_bracket + 1
                case '}':
                    middle_bracket = middle_bracket - 1
                case '[':
                    close_bracket = close_bracket + 1
                case ']':
                    close_bracket = close_bracket - 1
        if (bracket == 0 ) and (middle_bracket == 0) and (close_bracket == 0):
            return True
        else:
            return False




