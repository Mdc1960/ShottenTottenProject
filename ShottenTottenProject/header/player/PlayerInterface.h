#pragma once
#ifndef PLAYER_INTERFACE_H
#define PLAYER_INTERFACE_H

#include <memory>
#include <string>
#include "Hand.h"
#include "Bord.h"

/** Maximum number of cards allowed in a player's hand. */
static const unsigned int MAX_CARD_NUMBER_IN_PLAYER_HAND = 6;

/** Number of borders available for play. */
static const unsigned int ALLOW_NUBER_PLAY_BORDER = 9;

/** Number of card colors available. */
static const unsigned int ALLOW_NUBER_CARD_COLOR = 6;

/**
 * Common state and operations for players in the game.
 * Derived classes implement player-specific selection and claiming behavior.
 */
class PlayerInterface {
protected:
	std::string playerName; ///< The player's display name.
	Hand hand; ///< Cards currently held by the player.
	unsigned int idPlayer; ///< The player's identifier.

	unsigned int chooseBorderIndex = 0; ///< Index of the selected border.
	unsigned int chooseCardIndex = 0; ///< Index of the selected card in the hand.
	unsigned int revendicateBorderIndex = 0; ///< Index of the border to claim.

	bool isColorChooseValid = false; ///< Whether the color selection is valid.
	bool isBorderChooseValid = false; ///< Whether the border selection is valid.
	bool isRevendicateBorderValid = false; ///< Whether the claim selection is valid.
	bool isPlayerWantToRevendicate = false; ///< Whether the player wants to claim a border.

	/** Adds a card to the player's hand. */
	void pushCardInPlayerHand(std::unique_ptr<CardInterface> card);

public:
	/** Constructs a player with default-initialized state. */
	PlayerInterface();

	/**
	 * Constructs a player with the given name and identifier.
	 * @param name The player's display name.
	 * @param id The player's identifier.
	 */
	PlayerInterface(const std::string& name, unsigned int id);

	/** Destroys the player. */
	virtual ~PlayerInterface() = default;

	/** @return The player's display name. */
	std::string getPlayerName() const;
	/** @return The player's identifier. */
	unsigned int getIdPlayer() const;
	/** @return A mutable reference to the player's hand. */
	Hand& getHand();

	/** @return The index of the selected border. */
	const unsigned int getChooseBorderIndex() const;
	/** @return The index of the selected card. */
	const unsigned int getChooseCardIndex() const;
	/** @return The index of the border selected for claiming. */
	const unsigned int getRevendicateBorderIndex() const;
	/** @return Whether the player wants to claim a border. */
	const bool getIsPlayerWantToRevendicateValue() const;

	/** Sets the player's display name. @param name The new name. */
	void setPlayerName(const std::string& name);
	/** Sets the player's identifier. @param id The new identifier. */
	void setIdPlayer(unsigned int id);
	/** Prints information about the player. */
	void printPlayer();

	/** Sets the selected border index. @param borderIndex The index to store. */
	void setChooseBorderIndex(unsigned int& borderIndex);
	/** Sets the selected card index. @param cardIndex The index to store. */
	void setChooseCardIndex(unsigned int& cardIndex);
	/** Sets the border index selected for claiming. @param borderIndex The index to store. */
	void setRevendicateBorderIndex(unsigned int& borderIndex);

	/** Sets color-selection validity. @param b Whether the selection is valid. */
	void setIsChooseColorValid(bool&& b);
	/** Sets border-selection validity. @param b Whether the selection is valid. */
	void setIsChooseBoredValid(bool&& b);
	/** Sets claim-selection validity. @param b Whether the selection is valid. */
	void setIsRevendicateBorderValid(bool&& b);
	/** Sets whether the player wants to claim a border. @param b The player's choice. */
	void setIsPlayerWantToRevendicate(bool&& b);

	/** Fills the player's hand with clan cards drawn from the board. */
	void fillPlayerHandWithClanCardFronBordClanStack(Bord& bord);

	/**
	 * Removes and returns the card at the specified hand index.
	 * @param index Index of the card to remove.
	 * @return Ownership of the removed card.
	 */
	std::unique_ptr<CardInterface> popCardFromPlayerHandByIndex(unsigned int& index);

	/** Draws a card from a board stack and adds it to the player's hand. */
	void pickCardFromBordStacksAndAddInPlayerHand(Bord& bord);

	/** Executes the player's turn using the supplied board. */
	void play(Bord& bord);

	/** Selects a border; implemented by derived player types. */
	virtual void chooseBorne() = 0;
	/** Attempts to claim a border on the supplied board. */
	virtual void claim(Bord& bord) = 0;
	/** Displays the player's hand. */
	virtual void showHand();
	/** Selects a card; implemented by derived player types. */
	virtual void chooseCard() = 0;
};

#endif // PLAYER_INTERFACE_H
