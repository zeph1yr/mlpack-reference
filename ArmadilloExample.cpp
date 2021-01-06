#include <iostream>
 #include <armadillo>
 
 int main(int argc, const char **argv) {
     // Initialize the random generator
     arma::arma_rng::set_seed_random();
 
     // Create a 4x4 random matrix and print it on the screen
     arma::Mat<double> A = arma::randu(4,4);
    std::cout << "A:\n" << A << "\n";
 
    // Multiply A with his transpose:
     std::cout << "A * A.t() =\n";
    std::cout << A * A.t() << "\n";

     // Access/Modify rows and columns from the array:
    A.row(0) = A.row(1) + A.row(3);
    A.col(3).zeros();
     std::cout << "add rows 1 and 3, store result in row 0, also fill 4th column with zeros:\n";
     std::cout << "A:\n" << A << "\n";
 
     // Create a new diagonal matrix using the main diagonal of A:
    arma::Mat<double>B = arma::diagmat(A);
     std::cout << "B:\n" << B << "\n";

     // Save matrices A and B:
     A.save("A_mat.txt", arma::arma_ascii);
     B.save("B_mat.txt", arma::arma_ascii);

  return 0;
}

/*

Expected Output - 

A:
   0.4762   0.9687   0.2110   0.1289
   0.5869   0.2974   0.9578   0.5914
   0.3591   0.3654   0.3176   0.2554
   0.8000   0.5805   0.5479   0.9649

A * A.t() =
   1.2263   0.8459   0.6249   1.1833
   0.8459   1.7001   0.7746   1.7376
   0.6249   0.7746   0.4285   0.9198
   1.1833   1.7376   0.9198   2.2082

add rows 1 and 3, store result in row 0, also fill 4th column with zeros:
A:
   1.3868   0.8779   1.5058        0
   0.5869   0.2974   0.9578        0
   0.3591   0.3654   0.3176        0
   0.8000   0.5805   0.5479        0

B:
   1.3868        0        0        0
        0   0.2974        0        0
        0        0   0.3176        0
        0        0        0        0


*/
