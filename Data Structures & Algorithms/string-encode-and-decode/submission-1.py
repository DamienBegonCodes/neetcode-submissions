class Solution:

    def encode(self, strs: List[str]) -> str:
        out = ""
        for s in strs:
            out += str(len(s)) + '#' + s

        return out

    def decode(self, s: str) -> List[str]:
        out = []
        while s.find("#") != -1:
            n = s.find("#")
            l = int(s[:n])
            out.append(s[n + 1 : n + 1 + l])
            s = s[n + 1 + l:]
        return out
            
