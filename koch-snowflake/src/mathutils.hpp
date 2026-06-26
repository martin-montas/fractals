#ifndef SRC_MATHUTILS_HPP_
#define SRC_MATHUTILS_HPP_

#include <SDL2/SDL.h>

class MathUtils {
  public:
    /* @brief: calculate the mid point between 2 vectors.
     * @param[in]: the first vector
     * @param[in]: the second vector
     * @returns:  a properly changed vector
     */
    SDL_FPoint calc_mid_point_vec(SDL_FPoint v1, SDL_FPoint v2);

    /* @brief: calculate the distance between 2 vectors.
     * @param[in]: the first vector
     * @param[in]: the second vector
     * @returns:  float: distance between vectors
     */
    float calc_distance_vec(SDL_FPoint v1, SDL_FPoint v2);

    /* @brief: calculate the height between 2 vectors using the
     * Pythagorean theorem.
     * @param[in]: the first vector
     * @param[in]: the second vector
     * @returns:  float: height between vectors
     */
    float calc_height_vec(SDL_FPoint v1, SDL_FPoint v2);

    /* @brief: calculate the third 1/3 vectex for of another
     * vectex as explain here:
     * https://nostarch.com/download/PythonPlayground_SampleChapter1.pdf
     * @param[in]: the first vector
     * @param[in]: the second vector
     * @returns:  (SDL_FPoint) vector
     */
    SDL_FPoint calc_p2_vec(SDL_FPoint v1, SDL_FPoint v2);
};

#endif // SRC_MATHUTILS_HPP_
