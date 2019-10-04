import re
sen = "Hello guys my name is Bob. I'm a fella created by the amazing Hactoberfest team, and my job is to be your friend and bedazzle you!"
sen = max(re.sub(r'[^\w\s]','',sen).split(), key=len)
print(sen)
