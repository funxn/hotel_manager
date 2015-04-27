
typedef struct fee{
	int	feeType;					// 其他开销的编号
								// 0: 无开销 1: 食品消耗费 2.损坏赔偿费 3: 通话费 4: 水电费 5:上网费
	float	feeValue;					// 该种开销的金额
}FEE;

typedef struct customer{
	char	name[NAME_SIZE];
	int	sex;						// 0: male 1: female
	int	age;
	int	roomNumber;					// 由此可知房间的位置和类型
	int	roomDate[6];					// [year, month, day, hour, minute, second]
	char	id[ID_SIZE];
	char	company[COMPANY_SIZE];
	char	city[CITY_SIZE];
	FEE	fees[FEES_SIZE];
}CUSTOMER;

typedef struct room{
	char	hostID[ID_SIZE];
	int	price;
	int	roomNumber;
	int	roomType;					// 0:单人房 1:大床房 2:标间 3:商务行政房 4:豪华套房 5:总统套房
	int	cutPrice;
}ROOM;
