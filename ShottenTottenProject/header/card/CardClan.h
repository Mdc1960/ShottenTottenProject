#pragma once

#include "Color.h"
#include "CardInterface.h"

/** 
 * @brief A class representing a clan card.
 * This class inherits from CardInterface and provides an interface for clan cards in the game.
 */
class CardClan : public CardInterface
{
private:

    /** 
     * @brief The number of the card.
     */
    unsigned int numero;

    /** 
     * @brief The color of the card.
     */
    Color color;

protected:

    /** 
     * @brief Sets the color of the card.
     * @param newColor The new color to set.
     */
    void setColor(Color newColor) { color = newColor; }

    /** 
     * @brief Sets the number of the card.
     * @param newNumero The new number to set.
     */
    void setNumero(unsigned int newNumero) { numero = newNumero; }

public:

    /** 
     * @brief Constructor for the CardClan class.
     * @param num The number of the card.
     * @param col The color of the card.
     */
    CardClan(unsigned int num, Color col);

    /** 
     * @brief Gets the color of the card.
     * @return The color of the card.
     */
    Color getColor() { return color; }

    /** 
     * @brief Gets the name of the card.
     * @return The name of the card.
     */
    string getNamecard() override;

    /** 
     * @brief Prints the card.
     */
    void printCard() override;

    /** 
     * @brief Gets the color of the card.
     * @return The color of the card.
     */
    std::string getCardColor();

    /** 
     * @brief Gets the number of the card.
     * @return The number of the card.
     */
    unsigned int getCardNumber();
    
        
};
