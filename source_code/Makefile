CC		= gcc
LD		= gcc

CFLAGS		= -I include/ -c
LDFLAGS		= 

TARGET		= main.exe
OBJS		= main_module/main.o customer_check/customer_in.o customer_check/customer_out.o

# OPTIONS:
.PHONY: everything all clean

everything: $(TARGET)

all: clean everything

clean: 
	rm -f $(OBJS) $(TARGET)

### dependences describe:
$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(OBJS)

main_module/main.o: main_module/main.c include/const.h include/type.h include/global.h include/proto.h
	$(CC) $(CFLAGS) -o $@ $<

customer_check/customer_in.o: customer_check/customer_in.c include/const.h include/type.h
	$(CC) $(CFLAGS) -o $@ $<

customer_check/customer_out.o: customer_check/customer_out.c include/const.h include/type.h
	$(CC) $(CFLAGS) -o $@ $<
