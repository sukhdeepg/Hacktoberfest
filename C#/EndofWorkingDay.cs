public Boolean weekend()
    {
        DateTime date = DateTime.Now;

        if ((date.DayOfWeek == DayOfWeek.Saturday) || (date.DayOfWeek == DayOfWeek.Sunday))
        {
            Console.WriteLine("This is a weekend");
            return true;
        }
        else
        {
            return false;
        }
    }

    public Boolean EndofWorkingDay()
    {
        TimeSpan start = TimeSpan.Parse("08:00"); // 10 PM
        TimeSpan end = TimeSpan.Parse("18:00");   // 2 AM
        TimeSpan now = DateTime.Now.TimeOfDay;

        if (start <= end)
        {
            // start and stop times are in the same day
            if (now >= start && now <= end)
            {
                // current time is between start and stop
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            // start and stop times are in different days
            if (now >= start || now <= end)
            {
                // current time is between start and stop
                return false;
            }
            else
            {
                return true;
            }
        }
    }