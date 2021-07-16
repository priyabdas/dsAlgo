#define a class for node
#bst will have left and right child and self data


#Created by Priyabrata Das on 16/06/21

class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def main():
    print("BST Starts")
    bst = node(10)

if __name__ == '__main__':
    main()
