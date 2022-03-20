import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
# loading data
#importing r2 score
from sklearn.metrics import r2_score
from sklearn.model_selection import train_test_split
from sklearn import datasets, ensemble
import os

def func(filename):
	print(filename +" Added")
	val=r"C://Users//User//Desktop//.net core mvc authentication//DeloitteProject//DeloitteProject//wwwroot//temp//";
	val=val+filename
	print(val)
	raw = pd.read_csv(val)
	raw.date_time = pd.to_datetime(raw.date_time)
	months = raw.date_time.dt.month
	day_of_months = raw.date_time.dt.day
	hours = raw.date_time.dt.hour
	to_one_hot = raw.date_time.dt.day_name()
	# applying one hot encoding
	days = pd.get_dummies(to_one_hot)

	def daypart(hour):
		if hour in [2,3,4,5]:
			return "dawn"
		elif hour in [6,7,8,9]:
			return "morning"
		elif hour in [10,11,12,13]:
			return "noon"
		elif hour in [14,15,16,17]:
			return "afternoon"
		elif hour in [18,19,20,21]:
			return "evening"
		else: return "midnight"

	raw_dayparts = hours.apply(daypart)

	dayparts = pd.get_dummies(raw_dayparts)

	dayparts = dayparts[['dawn','morning','noon','afternoon','evening','midnight']]

	#is_weekend column
	day_names = raw.date_time.dt.day_name()
	is_weekend = day_names.apply(lambda x : 1 if x in ['Saturday','Sunday'] else 0)

	#is_holiday column
	is_holiday = raw.holiday.apply(lambda x : 0 if x == "None" else 1)

	weathers = pd.get_dummies(raw.weather_main)

	weatherdesc = pd.get_dummies(raw.weather_description)

	#including the features with single column nature

	features = pd.DataFrame({
		'temp' : raw.temp,
		'rain_1h' : raw.rain_1h,
		'snow_1h' : raw.snow_1h,
		'clouds_all' : raw.clouds_all,
		'month' : months,
		'day_of_month' : day_of_months,
		'hour' : hours,
		'is_holiday' : is_holiday,
		'is_weekend' : is_weekend
	})


	#concating with one-hot encode typed features
	features = pd.concat([features, days, dayparts, weathers, weatherdesc], axis = 1)


	target = raw.traffic_volume

	#splitting data

	X_train, X_test, y_train, y_test = train_test_split(features, target, test_size=0.3, shuffle = False)




	# Gradient Boosting Regressor
	params = {'n_estimators': 500,
			  'max_depth': 6,
			  'min_samples_split': 5,
			  'learning_rate': 0.1,
			  'loss': 'ls'}

	gb_reg = ensemble.GradientBoostingRegressor(**params)

	gb_reg.fit(X_train, y_train )


	y_true = y_test
	y_pred = gb_reg.predict(X_test)
	predict_df=pd.DataFrame(data=y_pred,columns=['Prediction'])
	df1=X_test[['temp','rain_1h','snow_1h','clouds_all']]
	df1['Prediction']=predict_df.Prediction.values
	val1=r"C:\Users\User\Desktop\.net core mvc authentication\DeloitteProject\DeloitteProject\wwwroot\final\\"
	#val1=os.path.join('C://Users//User//Desktop//.net core mvc authentication//DeloitteProject//DeloitteProject//wwwroot//final//', filename)
	val1=val1+filename
	print(val1)
	np.savetxt(val1, df1, delimiter = ",",header="temp,rain_1h,snow_1h,clouds_all,Prediction")

path_to_watch = "C:/Users/User/Desktop/.net core mvc authentication/DeloitteProject/DeloitteProject/wwwroot//temp"
before = dict ([(f, None) for f in os.listdir (path_to_watch)])
while 1:
        after = dict ([(f, None) for f in os.listdir (path_to_watch)])
        added = [f for f in after if not f in before]
        if added:
				
                func(added[0])
                break
        else:
             before = after