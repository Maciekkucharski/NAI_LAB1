//
// Created by Maciek on 02.11.2021.
//

#ifndef LAB1_GENETIC_H
#define LAB1_GENETIC_H

std::vector<int> selection_roulette(population_fitness_t fitnesses);
std::pair<genotype_t, genotype_t> empty_crossover_f(genotype_t a, genotype_t b);
genotype_t empty_mutation_f(genotype_t a, double);
population_t genetic_algorithm(
        std::function<double(genotype_t)> fitnes_f,
        const population_t init_population,
        double crossover_probability,
        double mutation_probability,
        std::function<std::pair<genotype_t, genotype_t>(genotype_t, genotype_t)> crossover_f,
        std::function<genotype_t(genotype_t, double)> mutation_f,
        std::function<std::vector<int>(population_fitness_t)> select_f,
        std::function<bool(population_t, population_fitness_t, int)> termination_cond = [](auto, auto, auto i) {
            return i < 100;
        });
double one_max(genotype_t gene);


#endif //LAB1_GENETIC_H
