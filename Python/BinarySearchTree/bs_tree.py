#Author: Stephen Pryor
#Date: September 25, 12

#-------------------------------------------START - subtree
class subtree:
  def __init__(self, value):
    self.val = value
    self.left = None
    self.right = None
#-------------------------------------------END - subtree

#-------------------------------------------START - bs_tree
class bs_tree:
  #constructor
  def __init__(self):
    self.root = None
    self.n = 0
  
  #START - Empty Function
  def empty(self):
    return self.root == None
  #END - Empty Function
  
  #START - Size Function
  def size(self):
    return self.n
  #END - Size Function
  
  #START - Insertion Function
  def insert(self, value):
    if self.empty():
      self.root = subtree(value)
      self.n = self.n + 1
    else:
      self._insert(value, self.root)
  
  #recursive insert      
  def _insert(self, value, leaf):
    if value > leaf.val:
      if leaf.right == None:
        leaf.right = subtree(value)
        self.n = self.n + 1
      else:
        self._insert(value, leaf.right)
    elif value < leaf.val:
      if leaf.left == None:
        leaf.left = subtree(value)
        self.n = self.n + 1
      else:
        self._insert(value, leaf.left)
  #END - Insertion Function
  
  #START - Search Function
  def search(self, value):
    return self._search(value, self.root)
  
  #recursive search
  def _search(self, value, leaf):
    if leaf == None:
      return False
    elif value == leaf.val:
      return True
    elif value > leaf.val:
      return self._search(value, leaf.right)
    else:
      return self._search(value, leaf.left)
  #END - Search Function
  
  #START - Deletion Function
  def remove(self, value):
    if not self.empty():
      self.root = self._remove(value, self.root)
  
  #recursive remove
  def _remove(self, value, leaf):
    if leaf != None:
      if value == leaf.val:
        if leaf.left == None and leaf.right == None:
          leaf = None
        elif leaf.left != None and leaf.right == None:
          leaf = leaf.left
        else:
          if leaf.right.left == None:
            leaf.right.left = leaf.left
            leaf = leaf.right
          else:
            prevLeaf = leaf.right 
            nextLeaf = leaf.right.left 
            while nextLeaf.left != None:
               prevLeaf = nextLeaf
               nextLeaf = nextLeaf.left
            leaf.val = nextLeaf.val
            prevLeaf.left = nextLeaf.right
        self.n = self.n - 1
      elif value > leaf.val:
        leaf.right = self._remove(value, leaf.right)
      elif value < leaf.val:
        leaf.left = self._remove(value, leaf.left)
    return leaf
  #END - Deletion Function

  #START - Inorder Traversal Function
  def print_inorder(self):
    self._print_inorder(self.root)
  
  #recursive print inorder 
  def _print_inorder(self, leaf):
    if leaf != None:
      self._print_inorder(leaf.left)
      print leaf.val
      self._print_inorder(leaf.right)
  #END - Inorder Traversal Function
#-------------------------------------------END - bs_tree
