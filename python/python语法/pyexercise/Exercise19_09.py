class BinaryTree:
    def __init__(self):
        self.__root = None
        self.__size = 0

    # Return True if the element is in the tree 
    def search(self, e):
        current = self.__root # Start from the root

        while current != None:
            if e < current.element:
                current = current.left
            elif e > current.element:
                current = current.right
            else: # element matches current.element
                return True # Element is found

        return False

    # Insert element e into the binary search tree
    # Return True if the element is inserted successfully 
    def insert(self, e):
        if self.__root == None:
            self.__root = self.createNewNode(e) # Create a new root
        else:
            # Locate the parent node
            parent = None
            current = self.__root
            while current != None:
                if e < current.element:
                    parent = current
                    current = current.left
                elif e > current.element:
                    parent = current
                    current = current.right
                else:
                    return False # Duplicate node not inserted

            # Create the new node and attach it to the parent node
            if e < parent.element:
                parent.left = self.createNewNode(e)
            else:
                parent.right = self.createNewNode(e)

        self.__size += 1 # Increase tree size
        return True # Element inserted

    # Create a new TreeNode for element e
    def createNewNode(self, e):
        return TreeNode(e)

    # Return the size of the tree
    def getSize(self):
        return self.__size
    
    # Inorder traversal from the root
    def inorder(self):
        self.inorderHelper(self.__root)

    # Inorder traversal from a subtree 
    def inorderHelper(self, r):
        if r != None:
            self.inorderHelper(r.left)
            print(r.element, end = " ")
            self.inorderHelper(r.right)

    # Postorder traversal from the root 
    def postorder(self):
        self.postorderHelper(self.__root)

    # Postorder traversal from a subtree 
    def postorderHelper(self, root):
        if root != None:
            self.postorderHelper(root.left)
            self.postorderHelper(root.right)
            print(root.element, end = " ")

    def inorderList(self):
        self.__tempList = []
        self.inorderList1(self.__root)
        return self.__tempList

    def inorderList1(self, root):
        if root != None:
            self.inorderList1(root.left)
            self.__tempList.append(root.element)
            self.inorderList1(root.right)

    def preorderList(self):
        self.__tempList = []
        self.preorderList1(self.__root)
        return self.__tempList

    def preorderList1(self, root):
        if root != None:
            self.__tempList.append(root.element)
            self.preorderList1(root.left)
            self.preorderList1(root.right)
            
    def postorderList(self):
        self.__tempList = []
        self.postorderList1(self.__root)
        return self.__tempList

    def postorderList1(self, root):
        if root != None:
            self.postorderList1(root.left)
            self.postorderList1(root.right)
            self.__tempList.append(root.element)
            
    # Preorder traversal from the root 
    def preorder(self):
        self.preorderHelper(self.__root)

    # Preorder traversal from a subtree 
    def preorderHelper(self, root):
        if root != None:
            print(root.element, end = " ")
            self.preorderHelper(root.left)
            self.preorderHelper(root.right)

    # Returns a path from the root leading to the specified element 
    def path(self, e):
        list = []
        current = self.__root # Start from the root

        while current != None:
            list.append(current) # Add the node to the list
            if e < current.element:
                current = current.left
            elif e > current.element:
                current = current.right
            else:
                break

        return list # Return an array of nodes

    # Delete an element from the binary search tree.
    # Return True if the element is deleted successfully
    # Return False if the element is not in the tree 
    def delete(self, e):
        # Locate the node to be deleted and its parent node
        parent = None
        current = self.__root
        while current != None:
            if e < current.element:
                parent = current
                current = current.left
            elif e > current.element: 
                parent = current
                current = current.right
            else:
                break # Element is in the tree pointed by current

        if current == None:
            return False # Element is not in the tree

        # Case 1: current has no left children
        if current.left == None:
            # Connect the parent with the right child of the current node
            if parent == None:
                self.__root = current.right
            else:
                if e < parent.element:
                    parent.left = current.right
                else:
                    parent.right = current.right
        else:
            # Case 2: The current node has a left child
            # Locate the rightmost node in the left subtree of
            # the current node and also its parent
            parentOfRightMost = current
            rightMost = current.left

            while rightMost.right != None:
                parentOfRightMost = rightMost
                rightMost = rightMost.right # Keep going to the right

            # Replace the element in current by the element in rightMost
            current.element = rightMost.element

            # Eliminate rightmost node
            if parentOfRightMost.right == rightMost:
                parentOfRightMost.right = rightMost.left
            else:
                # Special case: parentOfRightMost == current
                parentOfRightMost.left = rightMost.left     

        self.__size -= 1
        return True # Element deleted

    # Return true if the tree is empty
    def isEmpty(self):
        return self.__size == 0
        
    # Remove all elements from the tree
    def clear(self):
        self.__root == None
        self.__size == 0

    # Return the root of the tree
    def getRoot(self):
        return self.__root

class TreeNode:
    def __init__(self, e):
        self.element = e
        self.left = None  # Point to the left node, default None
        self.right = None # Point to the right node, default None

from tkinter import * # Import tkinter
import tkinter.messagebox
    
def insert():
    k = int(key.get())
    if tree.search(k): # key is in the tree already
        tkinter.messagebox.showinfo("Insertion Status", str(k) + 
                                    " is already in the tree")
    else:
        tree.insert(k) # Insert a new key
        canvas.delete("tree")
        displayTree(tree.getRoot(), width / 2, 30, width / 4)

def delete():
    k = int(key.get())
    if not tree.search(k): # key is in the tree already
        tkinter.messagebox.showinfo("Deletion Status", str(k) + 
                                    " is not in the tree")
    else:
        tree.delete(k) # Delete a key
        canvas.delete("tree")
        displayTree(tree.getRoot(), width / 2, 30, width / 4)

def inorder():
    tkinter.messagebox.showinfo("Inorder", str(tree.inorderList()))

def preorder():
    tkinter.messagebox.showinfo("Preorder", str(tree.preorderList()))

def postorder():
    tkinter.messagebox.showinfo("Postorder", str(tree.postorderList()))

# Display a subtree rooted at position (x, y)
def displayTree(root, x, y, hGap):
    if root == None: return # Empty tree

    # Display the root
    canvas.create_oval(x - radius, y - radius,
                       x + radius, y + radius, tags = "tree")
    canvas.create_text(x, y, 
                       text = str(root.element), tags = "tree")

    if root.left != None:
        # Draw a line to the left node
        connectTwoCircles(x - hGap, y + vGap, x, y)
        # Draw the left subtree recursively
        displayTree(root.left, x - hGap, y + vGap, hGap / 2)
          
    if root.right != None:
        # Draw a line to the right node
        connectTwoCircles(x + hGap, y + vGap, x, y)
        # Draw the right subtree recursively
        displayTree(root.right, x + hGap, y + vGap, hGap / 2)
        
# Connect two circles centered at (x1, y1) and (x2, y2) 
def connectTwoCircles(x1, y1, x2, y2):
    d = (vGap * vGap + (x2 - x1) * (x2 - x1)) ** 0.5
    x11 = x1 - radius * (x1 - x2) / d
    y11 = y1 - radius * (y1 - y2) / d
    x21 = x2 + radius * (x1 - x2) / d
    y21 = y2 + radius * (y1 - y2) / d
    canvas.create_line(x11, y11, x21, y21, tags = "tree")

window = Tk() # Create a window
window.title("DisplayBinaryTree") # Set a title

width = 200
height = 200
radius = 20
vGap = 50
canvas = Canvas(window, width = width, height = height)
canvas.pack()

frame1 = Frame(window) # Create and add a frame to window
frame1.pack()

tree = BinaryTree()
Label(frame1, text = "Enter a key").pack(side = LEFT)
key = StringVar()
entry = Entry(frame1, textvariable = key, 
              justify = RIGHT).pack(side = LEFT)
Button(frame1, text = "Insert", command = insert).pack(side = LEFT)
Button(frame1, text = "Delete", command = delete).pack(side = LEFT)
Button(frame1, text = "Show Inorder", command = inorder).pack(side = LEFT)
Button(frame1, text = "Show Preorder", command = preorder).pack(side = LEFT)
Button(frame1, text = "Show Postorder", command = postorder).pack(side = LEFT)

window.mainloop() # Create an event loop
