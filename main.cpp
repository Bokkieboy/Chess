
//
// Disclaimer:
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Board : public sf::Drawable, public sf::Transformable
{
public: 
};






int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    window.setFramerateLimit(30);
    const int board[64]={
       -1,-2,-3,-4,-5,-3,-2,-1,
       -6,-6,-6,-6,-6,-6,-6,-6,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        6, 6, 6, 6, 6, 6, 6, 6,
        1, 2, 3, 4, 5, 3, 2, 1};


  
    
    
    int i, boardLength = 8, x, size = 25;
    // Pixes
    for (;i <= boardLength; i++)
    {
        for (;x <= boardLength; x++)
        {
            if (i % 2 == 0)
            {
                sf::VertexArray square(sf::Quads, 4);
                square[0].position = sf::Vector2f(0.f, 0.f);
                square[1].position = sf::Vector2f(0.f, 50.f);
                square[2].position = sf::Vector2f(50.f, 50.f);
                square[3].position = sf::Vector2f(50.f, 0.f);
                        
                square[0].color = sf::Color::White;
                square[1].color = sf::Color::White;
                square[2].color = sf::Color::White;
                square[3].color = sf::Color::White;
            }
            else
            {
                sf::VertexArray squareBrown(sf::Quads, 4);
                squareBrown[0].position = sf::Vector2f(50.f, 50.f);
                squareBrown[1].position = sf::Vector2f(50.f, 100.f);
                squareBrown[2].position = sf::Vector2f(100.f, 100.f);
                squareBrown[3].position = sf::Vector2f(100.f, 50.f);
                
                squareBrown[0].color = sf::Color::Magenta;
                squareBrown[1].color = sf::Color::Magenta;
                squareBrown[2].color = sf::Color::Magenta;
                squareBrown[3].color = sf::Color::Magenta;

            }
        }
    }
    


    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }


        // Clear screen
        window.clear();
        
        //Draws the Square
        window.draw(square);
        
        window.draw(squareBrown);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
