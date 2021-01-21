#include <cspecs/cspec.h>
#include "EncryptThis.h"

context(tests){
    describe("String"){
        it("string_split"){
            char str[] = "Hello World {!##$)!}";
            int tokens = tokenCount(str,' ');
            char **words = string_split(str,tokens," ");
            should_string(words[0]) be equal to ("Hello");
            should_string(words[1]) be equal to ("World");
            should_string(words[2]) be equal to ("{!##$)!}");
            freeStringArr(words,tokens);
        }end

        it("split with different delimiter"){
            char str[] = "Unit$Testing$3";
            int tokens = tokenCount(str,'$');
            char **words = string_split(str,tokens,"$");
            should_string(words[0]) be equal to ("Unit");
            should_string(words[1]) be equal to ("Testing");
            should_string(words[2]) be equal to ("3");
            freeStringArr(words,tokens);
        }end

        it("intToString"){
            char *result = intToString(10432);
            should_string(result) be equal to ("10432");
            free(result);
        }end

        it("switchLetters"){
            char str[] = "Libro";
            switchLetters(str,0,(int)strlen(str)-1);
            should_string(str) be equal to ("oibrL");
        }end

        it("removeAt"){
            char str[] = "Emerson,Lake & Palmer";
            removeAt(str,7);
            should_string(str) be equal to ("EmersonLake & Palmer");
        }end

        it("ltrim"){
            char str[] = "       Marcos  ";
            ltrim(str);
            should_string(str) be equal to ("Marcos  ");
        }end

        it("rtrim"){
            char str[] = " asdasdsadsa          ";
            rtrim(str);
            should_string(str) be equal to (" asdasdsadsa");
        }end

        it("removeSpacesFromMiddle"){
            char str[] = "Marco     sss";
            removeSpacesFromMiddle(str);
            should_string(str) be equal to ("Marco sss");
        }end

        it("removeExtraSpaces"){
            char str[] = "        Mar     co    s              ";
            char *result = removeExtraSpaces(str);
            should_string(result) be equal to ("Mar co s");
            free(result);
        }end
    }end

    describe("Solution"){
        it("emptyString"){
            char *output = encrypt_this("");
            should_string(output) be equal to ("");
            free(output);
        }end

        it("oneCharacter"){
            char *output = encrypt_this("{");
            should_string(output) be equal to ("123");
            free(output);
        }end

        it("untrimmedString"){
            char *output = encrypt_this("      Abcd   Abcd");
            should_string(output) be equal to ("65dcb 65dcb");
            free(output);
        }end

        it("complexString"){
            char *output = encrypt_this("               The more he saw the                                 less he spoke    ");
            should_string(output) be equal to ("84eh 109ero 104e 115wa 116eh 108sse 104e 115eokp");
            free(output);
        }end
    }end
}
