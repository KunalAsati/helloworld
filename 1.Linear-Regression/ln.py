import matplotlib.pyplot as plt
import numpy  as np
import pandas as pd
from sklearn.linear_model import LinearRegression
dt = pd.read_csv("hours.csv")

X= dt['hrs']
y= dt['risk']

regressor = LinearRegression()
regressor.fit(X,y)
print("Accuracy : ", str(regressor.score(X, y) * 100))
y_pred=regressor.predict([[10]])
print(y_pred)
hours=int(input('Enter the no of hours:'))
eq=regressor.coef_*hours+regressor.intercept_
print('y = %f*%f+%f' %(regressor.coef_,hours,regressor.intercept_))
print('Equation for best fit line is: y=%f*x+%f' %(regressor.coef_,regressor.intercept_))
print("Risk Score: ", eq[0])
plt.plot(X, y, 'o')
plt.plot(X, regressor.predict(X));
plt.show()