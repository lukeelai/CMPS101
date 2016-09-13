import string
import numpy as np
import math

######## Begin code which needs to be modified ##########
class Node(object):
    def __init__ (self, key, value):
        self.key = key
        self.value = value
        self.next = None

#class LinkedList(object):
#    def __init__(self, key, value):
#        self.key = key
#        self.value = value
#        self.head = Node(key, value)

class MyChainDict(object):
    #initialize the hash table with 0s
    def __init__(self):
        size = 1048576                 #arbitrary large size
        self.table = np.zeros(size, dtype = object)
        return

    def hashing(self, key):
        #hash function
        return abs(hash(key)) % self.table.size

    def insert(self, key, value):
        #insert value at key, if there's no list, create one and insert value at top of list
        #else put element at the end of list
        i = self.hashing(key)
        if self.table[i] == 0:
            self.table[i] = Node(key, value)
            #Node.next = None
            return
        else:
            newnode = self.table[i]
            while newnode.next != None and newnode.key != key:
                newnode = newnode.next
            if newnode.key == key:
                newnode.value = value
            else:
                newnode.next = Node(key, value)

    def contains(self, key):
        #if there is nothing print message
        #else go through the lsit and print whats in the list
        i = self.hashing(key)
        if self.table[i] == 0:
            #print("no value in given key")
            return False
        else:
            currnode = self.table[i]
            while currnode != None:
                if currnode.key == key:
                    #print(currnode)
                    return True
                currnode = currnode.next
            return False

    def value(self, key):
        #returns the value of the key stored
        #similar to contains
        i = self.hashing(key)
        if self.table[i] == 0:
            return None
        else:
            currnode = self.table[i]
            while currnode != None:
                if currnode.key == key:
                    return currnode.value
                currnode = currnode.next
            return None


    def delete(self, key):
        #deletes the key
        #if nothing is there return nothing
        #if there is only one element in the list, set it to 0
        #if there is more than one element search for the value to delete
        i = self.hashing(key)
        if self.table[i] != 0:
            prevnode = null
            currnode = self.table[i]
            while currnode.next != None and currnode.key != key:
                prevnode = currnode
                currnode = currnode.next
            if currnode.key == key:
                if prevnode == None:
                    nextnode = currnode.next
                    del currnode
                    self.table[i] = nextnode
                else:  
                    nextnode = currnode.next
                    del currnode
                    prev.next = nextnode

    def get_key_values(self):
        #gets the value in the key by scanning through the table for the key
        #then scans the list for the value
        i = self.hashing(key)
        if self.table[i] == 0:
            return None
        else:
            currnode = self.table[i]
            while currnode != None and currnode.key != key:
                currnode = currnode.next
            if currnode == None:
                return None
            else:
                return currnode.value
    
    def dump(self):
        #prints out the key and its value as a pair using a simple for loop
        for i in self.table:
            if i == 0:
                print(0)
            else:
                currnode = i
                pair = (str(currnode.key), str(currnode.value))
                currnode = currnode.next
                while currnode != None: 
                    pair = '->' + (str(currnode.key), str(currnode.value))
                    currnode = currnode.next
                print(pair)

    def rehash(self):
        #rehashes the table if it is full
        oldsize = self.table.size
        newsize = oldsize * 2 + 1
        newtable = np.zeros(newsize, dtype = object)
        for i in range(oldsize):
            while oldsize != None:
                newtable[i] = self.table[i]

class MyOpenLinearDict(object):
    def __init__(self):
        size = 1048576               #arbitrary large size
        self.table = np.zeros(size, dtype = object)
        return
    
    def hashing(self, key):
        return abs(hash(key)) % self.table.size

    def insert(self, key, value):
        #if key is empty, insert pair
        #if there is an empty key, update it
        #else linear probe by go to the next empty key
        i = self.hashing(key)
        if self.table[i] == 0: 
            self.table[i] = (key, value)
            return
        elif self.table[i][0] == key:
            self.table[i] = (key, value)
            return
        else:
            while self.table[i % self.table.size] != 0:
                i += 1
            self.table[i % self.table.size] = (key, value)

    def contains(self, key):
        #if there is nothing, return false
        #else linearly probe the table for the key
        i = self.hashing(key)
        curr = self.table[i]
        if curr == 0:
            return False
        if curr[0] == key and type(curr) == tuple:
            return True
        else:
            while self.table[i % self.table.size] != 0:
                i += 1
                if (curr[0] == key) and (type(curr) == tuple):
                    return True
            return False

    def value(self, key):
        #if there is nothing in the key, return nothing
        #else linearly probe the table for the key
        i = self.hashing(key)
        curr = self.table[i]
        if curr == 0:
            return None
        if (curr[0] == key) and (type(curr) == tuple):
            return curr[1]
        else:
            while self.table[i % self.table.size] != 0:
                i += 1
                if (curr[0] == key) and (type(curr) == tuple):
                    return self.table[i % self.table.size][1]
            return None

    def delete(self, key):
        #if there is nothing in the table, return nothing
        #else linearly probe the table for the key/value to be deleted
        i = self.hashing(key)
        curr = self.table[i]
        if (curr == 0):
            return
        else:
            while (i % self.table.size) != 0:
                i += 1
                if (curr[0] == key) and (type(curr) == tuple):
                    self.table[i % self.table.size] = 1
        return

    def get_key_values(self):
        #gets the value in the key by linear probing through the table for the key
        #then gets the value
        i = self.hashing(key)
        if self.table[i] == 0:
            return None
        else:
            curr = self.table[i]
            while self.table[i % self.table.size] != 0:
                i += 1
                if (curr[0] == key) and (type(curr) == tuple):
                    return self.table[i % self.table.size][1]

    def dump(self):
        #simple for loop to print out the entire table linearly
        for i in np.arange(self.table.size):
            print(i, self.table[i])

    def rehash(self):
        #rehashes the table if it is full
        oldsize = self.table.size
        newsize = oldsize * 2 + 1
        newtable = np.zeros(newsize, dtype = object)
        for i in range(oldsize):
            while oldsize != None:
                newtable[i] = self.table[i]

class MyOpenQuadDict(object):
    def __init__(self):
        size = 1048576                #arbitrary large size
        self.table = np.zeros(size, dtype = object)
        return
    
    def hashing(self, key):
        return abs(hash(key)) % self.table.size

    def insert(self, key, value):
        #if key is empty, insert value
        #else quadratic probe by going to the next i ^ 2 key
        i = self.hashing(key)
        if self.table[i] == 0: 
            self.table[i] = (key, value)
            return
        elif self.table[i][0] == key:
            self.table[i] = (key, value)
            return
        else:
            counter = 0
            j = i
            while self.table[i % self.table.size] != 0:
                counter += 1
                j = counter + (i * i)
            self.table[j % self.table.size] = (key, value)

    def contains(self, key):
        #if there is nothing, return false
        #else quadraticly probe the table for the key
        i = self.hashing(key)
        curr = self.table[i]
        if curr == 0:
            return False
        else:
            counter = 0
            j = i
            while self.table[i % self.table.size] != 0:
                counter += 1
                j = counter + (i * i)
                if (type(self.table[j % self.table.size]) == tuple) and (self.table[j % self.table.size][0] == key):                 
                    return True
            return False

    def value(self, key):
        #if there is nothing in the key, return nothing
        #else quadraticly probe the table for the key
        i = self.hashing(key)
        curr = self.table[i]
        if curr == 0:
            return None
        else:
            counter = 0
            j = i
            while self.table[i % self.table.size] != 0:
                counter += 1
                j = counter + (i * i)
                if (type(self.table[j % self.table.size]) == tuple) and (self.table[j % self.table.size][0] == key):
                    return self.table[j % self.table.size][1]
            return None

    def delete(self, key):
        #if there is nothing in the table, return nothing
        #else linearly probe the table for the key/value to be deleted
        i = self.hashing(key)
        curr = self.table[i]
        if (curr[0] == key) and (type(curr) == tuple):
            curr = 0
            return
        else:
            counter = 0
            j = i
            while self.table[i % self.table.size] != 0:
                counter += 1
                j = counter + (i * i)
                if (type(self.table[j % self.table.size]) == tuple) and (self.table[j % self.table.size][0] == key):
                    self.table[j % self.table.size] = 0
        return

    def get_key_values(self):
        #gets the value in the key by quadraitc probinng
        i = self.hashing(key)
        if self.table[i] == 0:
            return None
        else:
            counter = 0
            j = i
            while self.table[i % self.table.size] != 0:
                counter += 1
                j = counter + (i * i)
                if (type(self.table[j % self.table.size]) == tuple) and (self.table[j % self.table.size][0] == key):
                    return self.table[j % self.table.size][1]
    
    def dump(self):
        #simple for loop to print out the entire table linearly
        for i in np.arange(self.table.size):
            print(i, self.table[i])

    def rehash(self):
        #rehashes the table if it is full
        oldsize = self.table.size
        newsize = oldsize * 2 + 1
        newtable = np.zeros(newsize, dtype = object)
        for i in range(oldsize):
            while oldsize != None:
                newtable[i] = self.table[i]

class MyChainSet(object):
    #intiate the set
    def __init__(self):
        self.mydict = MyChainDict()
        return

    #insert both the data and satalite data
    def insert(self, key):
        self.mydict.insert(key, key)
        return

    #shows what the key contains
    def contains(self, key):
        return self.mydict.contains(key)
 
    #simple for loop to print out the values and keys
    def dump(self):
        for k in self.mydict.get_key_values():
            print(k, k[0])
                
class MyOpenLinearSet(object):
    #intiate the set
    def __init__(self):
        self.mydict = MyOpenLinearDict()
        return

    #insert both the data and satalite data
    def insert(self, key):
        #value = self.key
        self.mydict.insert(key, key)
        return
    
    #shows what the key contains
    def contains(self, key):
        return self.mydict.contains(key)
    
    #simple for loop to print out the values and keys
    def dump(self):
        for k in self.mydict.get_key_values():
            print(k, k[0])

class MyOpenQuadSet(object):
    #intiate the set
    def __init__(self):
        self.mydict = MyOpenQuadDict()
        return

    #insert both the data and satalite data
    def insert(self, key):
        #value = self.key
        self.mydict.insert(key, key)
        return
    
    #shows what the key contains
    def contains(self, key):
        return self.mydict.contains(key)

    #simple for loop to print out the values and keys
    def dump(self):
        for k in self.mydict.get_key_values():
            print(k, k[0])


######## End code which needs to be modified ##########


# Store the set of stop words in a set object
stop_words_file = "stopwords.txt"
stop_words = MyOpenQuadSet()

with open(stop_words_file) as f:
    for l in f:
        stop_words.insert(l.strip())


# Download file from https://snap.stanford.edu/data/finefoods.txt.gz        
# Remember to gunzip before using
review_file = "foods.txt"

review_words = []
for i in range(5):
    review_words.append(MyChainDict())
    
with open(review_file, encoding='LATIN-1') as f:
    lines = f.readlines()
    idx = 0
    num_lines = len(lines) - 2
    while idx < num_lines:
        while not lines[idx].startswith("review/score"):
            idx = idx + 1

        # Jump through hoops to satisfy the Unicode encodings 
        l = lines[idx].encode('ascii', 'ignore').decode('ascii')
        l = l.strip().split(":")[1].strip()

        # Extract rating
        rating = int(float(l))
        while not lines[idx].startswith("review/text"):
            idx = idx + 1
            
        l = lines[idx].encode('ascii', 'ignore').decode('ascii').strip().lower()
        text = l.split(":")[1].strip()
        text = text.translate(str.maketrans("","", string.punctuation))

        # Extract words in the text 
        words = text.split(" ")
        # words = [x.strip(string.punctuation) for x in text.split(" ")]
        for w in words:
            if len(w) and not stop_words.contains(w):
                if review_words[rating - 1].contains(w):
                    count = review_words[rating - 1].value(w) + 1
                else:
                    count = 1
                review_words[rating - 1].insert(w, count)

# Print out the top words for each of the five ratings 
for i in range(5):
    freq_words = sorted(review_words[i].get_key_values(), key=lambda tup: tup[1], reverse=True)
    print(i+1, freq_words[0:20])
