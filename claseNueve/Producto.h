#include "inputs.h"

typedef struct
{
    char name[51];
    char description[51];
    float price;
    int isEmpty;
    int id;

}sProduct;

/** \brief To indicate that all position in the array are empty,
 *          this function puts a Zero in -isEmpty- in all position of the array
 * \param sProduct[] / List array of products
 * \param int / Array length
 * \return int / Returns (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initArray(sProduct listProducts[], int sizeArray);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
sProduct chargeProduct();

/** \brief To search for a free space in the array,
 *          this function search for a position that has a Zero in -isEmpty-
 * \param sProduct[] / List array of products
 * \param int / Array length
 * \return int / Returns the first empty position of the array
 *         (-1) if Error [Invalid length or NULL pointer] / (-2) if there is not free space.
 */
int findEmpty(sProduct listProducts[], int sizeArray);

/** \brief Charges in a existing list of products the data required in the first empty position.
 *
 * \param sProduct[] / List array of products
 * \param int / Array length
 * \param int Pointer / id
 * \return
 *
 */
int chargeListProducts(sProduct listProducts[], int sizeArray, int* id);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void printProduct(sProduct product);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void printListProducts(sProduct listProducts[], int sizeArray);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int discount25Percent(float num, float* result);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void exercise2(sProduct listProducts[], int sizeArray);
