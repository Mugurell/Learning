/*
** The information saved by the telephone company when you make a long
** distance phone call includes the date and time you placed the call. 
** It also includes three phone numbers: the one you called, the one you
** are calling from, and the one that will be billed. Each of these 
** phone numbers has three parts: the area code, the exchange, and the
** station number. Write a structure declaration for this billing info.
*/

struct billing_info {
	short	year;
	short	month;
	short	day;
	int 	time;
	struct 	PHONE_NUMBER	called;
	struct 	PHONE_NUMBER 	calling;
	struct 	PHONE_NUMBER 	billed;
}

struct PHONE_NUMBER {
	int 	area_code;
	int 	exchange;
	int 	station_number;
};

