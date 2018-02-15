def removeRedundent(string): 
   unqString = []
   [unqString.append(i) for i in string if not unqString.count(i)]
   return unqString

def generateMatrix(key):
	tempKey = "abcdefghijklmnoprstuvwxyz"
	tempKey = key + tempKey
	key = removeRedundent(tempKey)
	mSize = 5
	new = []
	for i in range(0,mSize):
		new.append(key[i*mSize:i*mSize+mSize])
	return key,new


def replace(ch,pos1,pos2,keyMatrix):
	if(pos1[0] == pos2[0]):
		c1 = keyMatrix[pos1[0]][(pos1[1]+1)%5]
		c2 = keyMatrix[pos1[0]][(pos2[1]+1)%5]
		return [c1,c2]
	if(pos1[1] == pos2[1]):
		c1 = keyMatrix[(pos1[0]+1)%5][pos1[1]]
		c2 = keyMatrix[(pos2[0]+1)%5][pos1[1]]
		return [c1,c2]
	else:
		c1 = keyMatrix[pos1[0]][pos2[1]]
		c2 = keyMatrix[pos2[0]][pos1[1]]
		return [c1,c2]



def replace2(ch,pos1,pos2,keyMatrix):
	if(pos1[0] == pos2[0]):
		c1 = keyMatrix[pos1[0]][(pos1[1]-1)%5]
		c2 = keyMatrix[pos1[0]][(pos2[1]-1)%5]
		return [c1,c2]
	if(pos1[1] == pos2[1]):
		c1 = keyMatrix[(pos1[0]-1)%5][pos1[1]]
		c2 = keyMatrix[(pos2[0]-1)%5][pos1[1]]
		return [c1,c2]
	else:
		c1 = keyMatrix[pos1[0]][pos2[1]]
		c2 = keyMatrix[pos2[0]][pos1[1]]
		return [c1,c2]


def encrypt(msg,key,keyMatrix):
	lenMsg = len(msg)
	if lenMsg%2 == 1:
		msg += "x"
	lenMsg = len(msg)
	encStr = []
	mSize = 2
	new = []
	for i in range(0,int(lenMsg/2)):
		new.append(msg[i*mSize:i*mSize+mSize])
	#print new
	for ch in new:		
		index = key.index(ch[0])		
		c1 = int(index/5),index%5
		index = key.index(ch[1])
		c2 = int(index/5),index%5
		encStr.append(replace(ch,c1,c2,keyMatrix))
	return encStr
		

def decrypt(msg,key,keyMatrix):
	lenMsg = len(msg)
	encStr = []
	mSize = 2
	new = []
	for i in range(0,int(lenMsg/2)):
		new.append(msg[i*mSize:i*mSize+mSize])
	#print new
	for ch in new:		
		index = key.index(ch[0])		
		c1 = int(index/5),index%5
		index = key.index(ch[1])
		c2 = int(index/5),index%5
		encStr.append(replace2(ch,c1,c2,keyMatrix))
	return encStr		



if(__name__ == "__main__"):
	print "Enter a key : "
	key = raw_input().strip().split()[0]
	keyMatrix,m = generateMatrix(key)
	for i in range(0,5):
		print m[i]
	print "Enter message small letters only :: "
	msg = raw_input().strip().lower()
	encStr = encrypt(msg,keyMatrix,m)
	eStr = ""
	for ch in encStr:
		eStr += ch[0]+ch[1]
	print "Encrypt :: ",eStr
	decStr = decrypt(eStr,keyMatrix,m)
	dStr = ""
	for ch in decStr:
		dStr += ch[0]+ch[1]
	print "Decrypt :: ",dStr
