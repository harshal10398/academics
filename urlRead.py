import urllib.request
import xlsxwriter
import time
workbook=xlsxwriter.Workbook('Stocks.xlsx')
worksheet=workbook.add_worksheet()
workbook.close()
row=0
col=0
while True:
	workbook=xlsxwriter.Workbook('Stocks.xlsx')
	worksheet=workbook.add_worksheet()
	with urllib.request.urlopen('http://finance.google.com/finance/info?client=ig&q=NSE%3ADIVISLAB') as response:
		html=response.read()
	string=html.decode("utf-8").split(',')

	cur_price=(float)((string[3].split(':')[1])[2:-2])
	hour=(int)((string[7].split(':')[1])[1:])
	minu=(int)((string[9].split(':')[1])[0:2])
	AMPM=(string[9].split(':')[1])[2:4]
	hour= 12+hour%12 if AMPM == 'PM'  else hour
	date=(((string[10].split(':')[1])[2:-3]).split('-'))
	year=(int)(date[0])
	month=(int)(date[1])
	day=(int)(date[2])
	change=(float)((string[11].split(':')[1])[2:-2])
#year month day hour minutes opening current change	
	worksheet.write(row,col,year)
	worksheet.write(row,col+1,month)
	worksheet.write(row,col+2,day)
	worksheet.write(row,col+3,hour)
	worksheet.write(row,col+4,minu)
	worksheet.write(row,col+5,cur_price+change)
	worksheet.write(row,col+6,cur_price)
	worksheet.write(row,col+7,change)
	row=row+1
	print('iteration: ', row)
	workbook.close()
	time.sleep(2)