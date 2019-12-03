#IFNDEF PAWN_H
#DEFINE PAWN_H

class Pawn : public Piece {
public:

//Piece constructor
	Pawn(colour side, std::string name, square position) 
		: Piece(side, name, position);

	~Pawn() override {};

	bool isMoveValid();
};


#endif
