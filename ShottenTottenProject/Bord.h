#ifndef GAME_BORD_H
#define GAME_BORD_H

#include "Border.h"
#include "Stack.h"
#include "Defausse.h"
#include "BorderBase.h"
#include "Observer.h"
#include <vector>
#include <unordered_map>

static const unsigned int MAX_BORDER_NUMBER_IN_BORD = 9;

class Game;

/**
 * @brief The Bord class represents the game board in the Shotten Totten game.
 * It manages the borders, stacks, and defausse, and implements the Observer pattern to receive updates from observable objects.
 */
class Bord : public Observer
{

private :

	/**
	 *  @brief A pointer to the clan stack. 
	*/
	std::unique_ptr<Stack> clanStack;

	/** 
	 * @brief A pointer to the tactic stack. 
	 */
	std::unique_ptr<Stack> tacticStack;

	/** 
	 * @brief A vector of unique pointers to Border objects representing the borders on the game board. 
	 */
	std::vector<std::unique_ptr<Border>> borders;

	/** 
	 * @brief A unique pointer to the defausse object. 
	 */
	std::unique_ptr<Defausse> defausse;

	
	/** 
	 * @brief A boolean flag indicating whether the clan stack is empty. 
	 */
	bool isClanStackEmpty = false;

	/** 
	 * @brief The capacity of the clan stack. 
	 */
	unsigned int clanStackCapacity;

	/** 
	 * @brief The capacity of the tactic stack. 
	 */
	unsigned int tacticStackCapacity;

	/** 
	 * @brief A static pointer to the singleton instance of the Bord class. 
	 */
	static Bord* instance;

	/** 
	 * @brief The constructor for the Bord class. 
	 */
	Bord();

	/** 
	 * @brief The destructor for the Bord class. 
	 */
	~Bord();

	/** 
	 * @brief The copy constructor for the Bord class. 
	 * @param bord The Bord object to be copied.
	 * @note This constructor is deleted to prevent copying of the Bord object.
	 */
	Bord(const Bord& bord) = delete;

	/** 
	 * @brief The move constructor for the Bord class. 
	 * @param bord The Bord object to be moved.
	 * @note This constructor is deleted to prevent moving of the Bord object.
	 */
	Bord(Bord&& bord) = delete;

	/** 
	 * @brief Creates the clan stack with the specified capacity. 
	 * @param capacity The capacity of the clan stack.
	 */
	void createClanStack(unsigned int&& capacity);

	/** 
	 * @brief Creates the tactic stack with the specified capacity. 
	 * @param capacity The capacity of the tactic stack.
	 */
	void createTacticStack(unsigned int&& capacity);

	/** 
	 * @brief Fills the borders with initial cards. 
	 */
	void fillBorders();


public :

	/** 
	 * @brief Gets the singleton instance of the Bord class. 
	 * @return A reference to the singleton instance of the Bord class.
	 */
	static Bord& getInstance();

	/** 
	 * @brief The number of cards put in the borders. 
	 */
	static unsigned int numberOfCardPutInBorders;

	/** 
	 * @brief Updates the Bord object based on changes in observable objects. 
	 * @param observable A pointer to the observable object that triggered the update. 
	 */
	void update(Observable* observable) override;
	
	/** 
	 * @brief Shuffles the clan stack. 
	 */
	void shuffledClanStack();

	/** 
	 * @brief Shuffles the tactic stack. 
	 */
	void shuffledTacticStack();

	/** 
	 * @brief Gets the index of the side of a border where a card was put. 
	 * @param borderIndex The index of the border.
	 * @param sideId The ID of the side of the border.
	 * @return The index of the side of the border where a card was put.
	 */
	const unsigned int getBorderSidePutCardIndex(unsigned int&& borderIndex, unsigned int&& sideId);

	/**
	 * @brief Prints the borders.
	 */
	void printBorders();

	/** 
	 * @brief Gets the size of the borders.
	 */
	size_t getBorderSize() const;

	/** 
	 * @brief Prints the first player's border side.
	 */
	void printFirstPlayerBorderSide();

	/** 
	 * @brief Prints the second player's border side.
	 */
	void printSecondPlayerBorderSide();

	/** 
	 * @brief Creates the border stacks with the specified capacities. 
	 * @param clanCapacity The capacity of the clan stack.
	 * @param tacticCapacity The capacity of the tactic stack.
	 */
	void createBordStacks(unsigned int&& clanCapacity, unsigned int&& tacticCapacity);

	/** 
	 * @brief Puts a card in the border by player ID and column index.
	 * @param card A unique pointer to the card to be put in the border.
	 * @param playerId The ID of the player putting the card.
	 * @param columnIndex The index of the column in the border where the card will be placed. 
	 */
	void putCardInBorderByPlayerIdAndColumnIndex(std::unique_ptr<CardInterface> card,unsigned int&& playerId, unsigned int&& columnIndex);

	/** 
	 * @brief Shows the clan stack.
	 */
	void showClanStack();

	/** 
	 * @brief Shows the tactic stack.
	 */
	void showTacticStack();

	/** 
	 * @brief Pops a card from the clan stack and returns it.
	 * @return A unique pointer to the popped card from the clan stack.
	 */
	std::unique_ptr<CardInterface> popAndGetCardFromClanStack();

	/** 
	 * @brief Pops a card from the tactic stack and returns it.
	 * @return A unique pointer to the popped card from the tactic stack.
	 */
	std::unique_ptr<CardInterface> popAndGetCardFromTacticStack();

	/** 
	 * @brief Sets whether the clan stack is empty.
	 * @param b True if the clan stack is empty, false otherwise.	
	 */
	void setIsClanStackEmpty(bool&& b);

	/** 
	 * @brief Gets whether the clan stack is empty.
	 * @return True if the clan stack is empty, false otherwise.
	 */
	const bool getIsClanStackEmpty() const;

	/** 
	 * @brief Claims a border.
	 * @param playerRevendicateBorderIndex The index of the border to be claimed.
	 * @return The index of the claimed border.
	 */
	const unsigned int claim(unsigned int& playerRevendicateBorderIndex);

	/** 
	 * @brief Gets the capacity of a border by its index.
	 * @param borderIndex The index of the border.
	 * @return The capacity of the specified border.
	 */
	const unsigned int getBorderCapacityByIndex(unsigned int borderIndex);

	/** 
	 * @brief Sets the last player side put card.
	 * @param borderIndex The index of the border.
	 * @param lastPlayerSidePutCard The last player side put card to set.
	 */
	void setLastPlayerSidePutCard(unsigned int borderIndex, unsigned int lastPlayerSidePutCard);

	/** 
	 * @brief Gets the last player side put card.
	 * @param borderIndex The index of the border.
	 * @return The last player side put card for the specified border index.
	 */
	const unsigned int getLastPlayerSidePutCard(unsigned int borderIndex);

	/** 
	 * @brief Fills the player revendicate map.
	 * @param revendicateColumn The column index for revendication.
	 * @param playerSideId The ID of the player's side.
	 * @return An unordered map containing the player revendicate information.
	 */
	std::unordered_map<std::string, unsigned int> fillPlayerRevendicateMap(unsigned int& revendicateColumn, unsigned int&& playerSideId);

};

#endif