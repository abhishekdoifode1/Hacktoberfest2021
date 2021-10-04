public class TimeConverter {
    public static class Second {
        public static int toMinute(int seconds) {
            return Math.floorDiv(seconds, 60);
        }

        public static int toHour(int seconds) {
            return Math.floorDiv(seconds, 3600);
        }
    }

    public static class Minute {
        public static int toSecond(int minutes) {
            return minutes * 60;
        }

        public static int toHour(int minutes) {
            return Math.floorDiv(minutes, 60);
        }
    }

    public static class Hour {
        public static int toSecond(int hours) {
            return hours * 3600;
        }

        public static int toMinute(int hours) {
            return hours * 60;
        }
    }
}
