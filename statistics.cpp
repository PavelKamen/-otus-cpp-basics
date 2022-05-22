#include <iostream>
#include <limits>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};

class Mean : public IStatistics {
public:
	Mean() : m_mean{0}, m_sum{0}, m_counter{0} {
	}

	void update(double next) override {
		m_sum+=next;
		m_counter++;
		m_mean = m_sum/m_counter;
	}

	double eval() const override {
		return m_mean;
	}

	const char * name() const override {
		return "mean";
	}

private:
	
	double m_mean;
	double m_sum;
	int m_counter;
};



int main() {

	const size_t statistics_count = 3;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
    statistics[2] = new Mean{};
    
	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; i++) {
			statistics[i]->update(val);   // min update
			statistics[++i]->update(val); // max update
			statistics[i+2]->update(val); // mean update
		}
	}
	
	//void fill_vector(std::vector<int> &values, size_t count) {
	//values.resize(count);
	//for (size_t i = 0; i < count; ++i) {
	//values[i] = static_cast<int>(i);
	//}
//}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
		std::cout << statistics[i+1]->name() << " = " << statistics[i+1]->eval() << std::endl;
		std::cout << statistics[i+2]->name() << " = " << statistics[i+2]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
		delete statistics[i++];
		delete statistics[i+2];
	}

	return 0;
}
