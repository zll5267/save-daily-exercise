
G++FLAG=-I../cpp -L/usr/local/lib -lprotobuf -lpthread

PROTO:
	protoc -I=./ --cpp_out=cpp ./addressbook.proto

ADDPEOPLE:
	g++ -std=c++11 -o addperson ./src/addPerson.cc ./cpp/addressbook.pb.cc $(G++FLAG)

LISTPEOPLE:
	g++ -std=c++11 -o listperson ./src/listPerson.cc ./cpp/addressbook.pb.cc $(G++FLAG)
