class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        for i in range(9):
            count = [0] * 9
            for j in range(9):
                num = board[i][j]
                if (num != "."):
                    num = int(num) - 1
                    if count[num] > 0:
                        return False
                    count[num] += 1

        for j in range(9):
            count = [0] * 9
            for i in range(9):
                num = board[i][j]
                if (num != "."):
                    num = int(num) - 1
                    if count[num] > 0:
                        return False
                    count[num] += 1

        for k in range(9):
            count = [0] * 9
            for l in range(9):
                i = k // 3 * 3 + l // 3
                j = k % 3 * 3 + l % 3
                num = board[i][j]
                if (num != "."):
                    num = int(num) - 1
                    if count[num] > 0:
                        return False
                    count[num] += 1

        return True