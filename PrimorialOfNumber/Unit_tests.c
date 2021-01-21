#include <cspecs/cspec.h>
#include "PrimorialOfNumber.h"

context(tests){
    describe("PrimeFunctions"){
        it("isPrime(0) should return false"){
            should_bool(isPrime(0)) be falsey;
        }end

        it("isPrime(1) should return false"){
            should_bool(isPrime(1)) be falsey;
        }end

        it("isPrime(2) should return true"){
            should_bool(isPrime(2)) be truthy;
        }end

        it("isPrime(47) should return true"){
            should_bool(isPrime(47)) be truthy;
        }end

        it("isPrime(946) should return false"){
            should_bool(isPrime(946)) be falsey;
        }end

        it("The first prime is 2"){            
            should_int(nthPrime(1)) be equal to (2);
        }end

        it("The 19th prime is 67"){
            should_int(nthPrime(19)) be equal to (67);
        }end

    }end

    describe("Solution"){
        it("Primorial of 1 is 2"){
            should_int(num_primorial(1)) be equal to (2);
        }end

        it("Primorial of 2 is 6"){
            should_int(num_primorial(2)) be equal to (6);
        }end

        it("Primorial of 20 is 1736424406"){
            should_int(num_primorial(32)) be equal to (1736424406);
        }end
    }end
}