#define a class for node
#bst will have left and right child and self key


#Created by Priyabrata Das on 16/06/21

class node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

    #bst add an element
    def add(self, key):
        if self.key == key:
            return

        if key < self.key:
            if self.left == None:
                self.left = node(key)
                return
            else:
                self.left.add(key)
        if key > self.key:
            if self.right == None:
                self.right = node(key)
                return
            else:
                self.right.add(key)

    def search(self,targetKey):
        if targetKey == self.key:
            print("Key found !!")
            return
        if self.left and targetKey < self.key:
            return self.left.search(targetKey)
        if self.right and targetKey > self.key:
            return self.right.search(targetKey)
        print ("Key not found")

    #inorder tree traverse    
    def traverseInorder(self):
        if self.left:
            self.left.traverseInorder()
        print(self.key)
        if self.right:
            self.right.traverseInorder()

def main():
    print("BST Starts")
    elements = [40,60,30,35,45,70,75,80,65]
    bst = node(50)
    for element in elements:
        bst.add(element)
    bst.traverseInorder()
    bst.search(60)

if __name__ == '__main__':
    main()
