#IFNDEF PIECE_H
#DEFINE PIECE_H

class Piece {
public:

//Piece constructor
	Piece(colour, std::string name, square position) 
		{colour(colour), name(name), hasMoved(false)};

	virtual Piece{};

	std::string getName();

	std::string getColour();

	std::string getPossibleMoves();

protected:

	bool hasMoved;
	square position;
	colour colour;

};


#endif
