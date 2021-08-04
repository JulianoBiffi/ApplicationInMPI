#include <string>
using namespace std;

class Home
{
	public:
		/// <summary>
		/// Get or set current home identify
		/// </summary>
		int Identify;

		/// <summary>
		/// Get or set current city of this home
		/// </summary>
		string CityName;

		/// <summary>
		/// Get or set lenght of home
		/// </summary>
		double LengthOfHome;

		/// <summary>
		/// Get or set width of home
		/// </summary>
		double WidthOfHome;

		/// <summary>
		/// Get or set current area of this home
		/// </summary>
		double HomeArea() {
			return WidthOfHome * LengthOfHome;
		};

		/// <summary>
		/// Get one random city name between 10 cities.
		/// </summary>
		/// <returns>String with random name</returns>
		string GetRandomCityName() {
			string choices[] =
			{
				"Columbus",
				"Dallas",
				"Mesa",
				"Austin",
				"Miami",
				"Tulsa",
				"New Orleans",
				"Omaha",
				"Atlanta",
				"Sacramento"
			};

			return choices[rand() % choices->size() + 1];
		};

		Home BuildRandom() {
			Home returnObject;
			returnObject.Identify = rand();
			returnObject.CityName = GetRandomCityName();
			returnObject.LengthOfHome = rand() % 100 + 1;
			returnObject.WidthOfHome = rand() % 100 + 1;

			return returnObject;
		}
};