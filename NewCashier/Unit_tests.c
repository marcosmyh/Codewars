#include <cspecs/cspec.h>
#include "NewCashier.h"

context(tests){
    describe("String"){
        it("Substring"){
            char str[] = "GetOrders";
            char *result = substr(str,1,2);
            should_string(result) be equal to ("et");
            free(result);
        }end
    }end
    
    describe("Solution"){
        it("obtainItemCoke"){      
            char str[] = "co";      
            char *item = obtainItem('c',str);
            should_string(item) be equal to ("Coke");
        }end

        it("obtainItemChicken"){
            char str[] = "ch";
            char *item = obtainItem('c',str);
            should_string(item) be equal to ("Chicken");
        }end

        it("ocurrencesWithMultipleItems"){
            char str[] = "MilkshakeBurgerFriesSandwichOnionrings";
            int len;
            int *arr = determineOcurrences(str,&len);
            int numbers[] = {6,0,1,4,5};
            for(int i = 0;i < len;i++)
                should_int(arr[i]) be equal to (numbers[i]);
            free(arr);
        }end

        it("oneItem"){
            char str[] = "milkshake";
            char *result = get_order(str);
            should_string(result) be equal to ("Milkshake");
            free(result);
        }end

        it("twoItems"){
            char str[] = "burgerFries";
            char *result = get_order(str);
            should_string(result) be equal to ("Burger Fries");
            free(result);
        }end

        it("multipleItems"){
            char str[] = "CokeChickenMilkshakePizzaSandwichOnionringsFriesChicken";
            char *result = get_order(str);
            should_string(result) be equal to ("Fries Chicken Chicken Pizza Sandwich Onionrings Milkshake Coke");
            free(result);
        }end
    }end
}
