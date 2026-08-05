import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

    // classe que representa um pais do csv
    static class Country {
        String country;
        long confirmed;
        long deaths;
        long recovery;
        long active;

        Country(String line) {
            String[] p = line.split(",");
            country = p[0];
            confirmed = Long.parseLong(p[1]);
            deaths = Long.parseLong(p[2]);
            recovery = Long.parseLong(p[3]);
            active = Long.parseLong(p[4]);
        }

        public String getCountry() {
            return country;
        }

        public long getConfirmed() {
            return confirmed;
        }

        public long getDeaths() {
            return deaths;
        }

        public long getActive() {
            return active;
        }
    }

    public static void main(String[] args) throws IOException {

        // le os 4 inteiros da entrada
        Scanner sc = new Scanner(System.in);

        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int n3 = sc.nextInt();
        int n4 = sc.nextInt();

        // le e processa o arquivo csv
        List<Country> countries = Files.lines(Paths.get("dados.csv"))
                .map(Country::new)
                .collect(Collectors.toList());

        // soma os ativos dos paises com confirmados >= n1
        long somaActive = countries.stream()
                .filter(c -> c.getConfirmed() >= n1)
                .mapToLong(Country::getActive)
                .sum();

        System.out.println(somaActive);

        // dentre os n2 com mais ativos, soma as mortes dos n3 com menos confirmados
        long somaDeaths = countries.stream()
                .sorted(Comparator.comparingLong(Country::getActive).reversed())
                .limit(n2)
                .sorted(Comparator.comparingLong(Country::getConfirmed))
                .limit(n3)
                .mapToLong(Country::getDeaths)
                .sum();

        System.out.println(somaDeaths);

        // imprime os n4 paises com mais confirmados em ordem alfabetica
        countries.stream()
                .sorted(Comparator.comparingLong(Country::getConfirmed).reversed())
                .limit(n4)
                .map(Country::getCountry)
                .sorted()
                .forEach(System.out::println);

        sc.close();
    }
}