chess: ChessMain.o ChessBoard.o piece.o rook.o knight.o bishop.o king.o queen.o pawn.o helper.o
	g++ -Wall -g ChessMain.o ChessBoard.o piece.o rook.o knight.o bishop.o king.o queen.o pawn.o helper.o -o chess

ChessMain.o: ChessMain.cpp
	g++ -Wall -g -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h
	g++ -Wall -g -c ChessBoard.cpp

piece.o: piece.cpp piece.h
	g++ -Wall -g -c piece.cpp

rook.o: rook.cpp rook.h
	g++ -Wall -g -c rook.cpp

knight.o: knight.cpp knight.h
	g++ -Wall -g -c knight.cpp

bishop.o: bishop.cpp bishop.h
	g++ -Wall -g -c bishop.cpp

king.o: king.cpp king.h
	g++ -Wall -g -c king.cpp

queen.o: queen.cpp queen.h
	g++ -Wall -g -c queen.cpp

pawn.o: pawn.cpp pawn.h
	g++ -Wall -g -c pawn.cpp

helper.o: helper.cpp helper.h
	g++ -Wall -g -c helper.cpp

clean:
	rm -f *.o chess
