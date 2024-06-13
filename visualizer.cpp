#include "visualizer.hpp"

void Visualizer::run(TTF_Font* font){
    
        while (SDL_PollEvent(&event)){
            events();
        }

        if(sdl::button("quicksort",100,100,200,100,60,60,60,renderer,font)) currentAlgorithm = QUICKSORT;
        if(sdl::button("bubble sort",100,210,200,100,60,60,60,renderer,font)) currentAlgorithm = BUBBLESORT;
        if(sdl::button("insertion sort",100,320,200,100,60,60,60,renderer,font)) currentAlgorithm = INSERTIONSORT;
        if(sdl::button("selection sort",100,430,200,100,60,60,60,renderer,font)) currentAlgorithm = SELECTIONSORT;
        if(sdl::button("bogosort",100,540,200,100,60,60,60,renderer,font)) currentAlgorithm = BOGOSORT;
        if(sdl::button("miracle sort",100,650,200,100,60,60,60,renderer,font)) currentAlgorithm = MIRACLESORT;

        if(sdl::button("shuffle",400,100,200,100,60,60,60,renderer,font)) if(!m_sorting) shuffle(m_array,m_array.size());
        if(sdl::button("start",400,210,200,100,60,60,60,renderer,font)){
            if(!m_sorting){

                m_sorting = true;
                switch(currentAlgorithm){
                    case QUICKSORT:
                        quickSort(m_array, 0, m_array.size() - 1,font);
                        m_sorting=0;
                        break;
                    
                    case BUBBLESORT:
                        bubbleSort(m_array,m_array.size(),font);
                        break;

                    case INSERTIONSORT:
                        insertionSort(m_array,m_array.size(),font);
                        break;

                    case SELECTIONSORT:
                        selectionSort(m_array,m_array.size(),font);
                        break;

                    case BOGOSORT:
                        bogoSort(m_array,m_array.size(),font);
                        break;
                    
                    case MIRACLESORT:
                        // miracleSort(m_array,m_array.size(),font);
                        m_sorting=0;
                        // break;

                    default:
                        break;
                }
            }
        }
        if(sdl::button("resize",400,320,200,100,60,60,60,renderer,font) && !m_sorting){
            int size;
            do{
                std::cout<<"insert the size of the test (2-230):\n";
                std::cin>>size;
                if(size<2||size>230) std::cout<<"the size is "<<((size>230) ? "too big, " : "too small, ");
            }while(size<2||size>230);

            m_array.clear();
            for(int i=1;i<=size;++i){
                m_array.push_back(i);
            }
        }
        
        int offsett = 0;
        for(int i:m_array){
            SDL_Rect num;
            num.w=700/m_array.size();
            num.h=i*650/m_array.size();
            num.y=750-num.h;
            num.x=700+offsett;
            offsett+=num.w;

            if(m_array[i-1]==i) SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); 
            else SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 

            SDL_RenderFillRect(renderer, &num); 
            SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
            SDL_RenderDrawRect(renderer, &num);
        }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
}

void Visualizer::events(){
    
    switch(event.type){  
            case SDL_QUIT:
                m_quit = true;
                break;
                
            default: 
                break;
    }

}