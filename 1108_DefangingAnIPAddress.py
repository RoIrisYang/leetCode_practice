class Solution:
    def defangIPaddr(self, address: str) -> str:
        output = ""
        for x in address:
            output += (x.replace(".", "[.]") if x == "." else x)
        return output