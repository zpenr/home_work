import abc

class ChessPiece(abc.ABC):
    def __init__(self, horizontal, vertical):
        self.horizontal = horizontal
        self.vertical = vertical

    @abc.abstractmethod
    def can_move(self):
        pass

class King(ChessPiece):
    def __init__(self, horizontal, vertical):
        super().__init__(horizontal, vertical)
    
    def can_move(self, horizontal, vertical):
        if abs(ord(self.horizontal) - ord(horizontal)) <= 1 and abs(self.vertical - vertical) <=1:
            return True
        return False
    
class Knight(ChessPiece):
    def __init__(self, horizontal, vertical):
        super().__init__(horizontal, vertical)

    def can_move(self, horizontal, vertical):

        diff_h = abs(ord(self.horizontal) - ord(horizontal))
        diff_v = abs(self.vertical - vertical)

        if (diff_h == 1 and diff_v == 2) or (diff_h == 2 and diff_v == 1):
            return True
            
        return False