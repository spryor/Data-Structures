#Author: Stephen Pryor
#Date: September 25, 12

#-------------------------------------------START - ll_element
class ll_element:
  #constructor
  def __init__(self, value):
    self.val = value
    self.next = None
#-------------------------------------------END - ll_element

#-------------------------------------------START - singlyLinkedList
class singlyLinkedList:
  #constructor
  def __init__(self):
    self.root = None
    self.last = None
    self.n = 0
  
  #START - Empty Function
  def empty(self):
    return self.root == None
  #END - Empty Function
  
  #START - Size Function
  def size(self):
    return self.n
  #END - Size Function
  
  #START - Insert Function
  def insert(self, value):
    if self.root == None:
      self.root = ll_element(value)
      self.last = self.root  
    else:
      self.last.next = ll_element(value)
      self.last = self.last.next
    self.n = self.n + 1
  #END - Insert Function
  
  #START - Remove Function
  def remove(self, value):
    if not self.empty():
      if self.root.val == value:
        self.root = self.root.next
        self.n = self.n - 1
      else:
        prev = self.root
        while prev.next != None:
          if prev.next.val == value:
            prev.next = prev.next.next
            self.n = self.n - 1
            break
          prev = prev.next
  #END - Remove Function
  
  #START - Search Function
  def search(self, value):
    next = self.root
    found = False
    while next != None:
      if next.val == value:
        found = True
        break
      next = next.next
    return found
  #END - Search Function
  
  #START - getAsList Function  
  def getAsList(self):
    next = self.root
    lst = []
    while next != None:
      lst.append(next.val)
      next = next.next
    return lst
  #END - getAsList Function  
#-------------------------------------------END - singlyLinkedList
