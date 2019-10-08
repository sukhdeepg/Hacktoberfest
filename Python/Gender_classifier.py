#  A simple ML program
from sklearn.svm import SVC


clf = SVC(gamma = 'auto',kernel = 'rbf')


# [height, weight, shoe_size]

X = [[181, 80, 44], [177, 70, 43], [160, 60, 38], [154, 54, 37], [166, 65, 40],

     [190, 90, 47], [175, 64, 39],

     [177, 70, 40], [159, 55, 37], [171, 75, 42], [181, 85, 43]]


# [gender]

Y = ['male', 'male', 'female', 'female', 'male', 'male', 'female', 'female',

     'female', 'male', 'male']



#  training them on our data

clf = clf.fit(X, Y)


prediction = clf.predict([[153, 48, 37]])



# predicting the reusults 



print(prediction)
