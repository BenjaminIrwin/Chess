OBJ = ChessMain.o ChessBoard.o piece.o rook.o knight.o bishop.o king.o queen.o pawn.o helper.o
EXE = chess 
CXX = g++
CXXFLAGS = -Wall -g -Wextra -MMD

$(EXE): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $<

-include $(OBJ:.o=d)

clean:
	rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)

.PHONY: clean
